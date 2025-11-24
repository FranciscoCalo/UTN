#include <iostream>
#include <fstream>
#include <array>
#include <cmath>
#include <cassert>

struct Punto{double x,y; };
struct SecuenciaDePuntos
{
    std::array<Punto, 100> a;
    unsigned n; //ocupación total del array
};
enum struct Color { Rojo, Verde, Azul };
struct Poligono
{
    SecuenciaDePuntos secuenciadepuntos;
    Color color;
};

struct MisPoligonos
{
    std::array<Poligono, 100> a;
    unsigned n; //ocupación total del array
};

bool areNear(double, double, double = 0.1); // verifica si dos valores están cerca dentro de una tolerancia (usamos para asserts)
unsigned getCantidadLados(const Poligono&); // calcula la cantidad de lados de un polígono
unsigned getCantidadPuntos(const SecuenciaDePuntos&); // calcula la cantidad de puntos en una secuencia de puntos
double getPerimetro(const Poligono&); // calcula el perímetro de un polígono
double getDistanciaPuntos(const Punto&, const Punto&); // calcula la distancia entre dos puntos
Punto leerPunto(std::ifstream&);    // getPunto lee un punto desde un stream
void removePunto(SecuenciaDePuntos&, Punto); // elimina el punto X,Y de una secuencia de puntos
void addPunto(SecuenciaDePuntos&, Punto); // agrega un punto al final de una secuencia de puntos
Poligono crearPoligono(std::ifstream&); // crea un polígono leyendo desde un stream (lee puntos - agrega puntos)
void ordenarPorPerimetro(MisPoligonos&); // ordena los polígonos por perímetro 
void ordenarPorCantidadLados(MisPoligonos&); // ordena los polígonos por cantidad de lados
void escribirPoligonos(const MisPoligonos&, const std::string&); // escribe los polígonos en un archivo (sobreescribe)
void escribirPoligonosAppend(const MisPoligonos&, const std::string&);// Agrega al archivo de polígonos ordenados creado anteriormentea


int main() {
 
// Test 1: Triángulo  (0,0) - (3,0) - (3,4)  -> perímetro 12
    SecuenciaDePuntos s1;
    s1.n = 0;

    addPunto(s1, {0,0});
    addPunto(s1, {3,0});
    addPunto(s1, {3,4});
    Poligono tri;
    tri.secuenciadepuntos = s1;
    tri.color = Color::Rojo;

    assert(getCantidadPuntos(tri.secuenciadepuntos) == 3);
    assert(getCantidadLados(tri) == 3);

    double per_tri = getPerimetro(tri);
    // const double eps = 1e-9;
    // assert(std::fabs(per_tri - 12.0) < eps);
    assert(areNear(getPerimetro(tri),12));

    // Test 2: Cuadrado de lado 2 -> perímetro 8
    SecuenciaDePuntos s2;
    s2.n = 0;
    addPunto(s2, {0,0});
    addPunto(s2, {2,0});
    addPunto(s2, {2,2});
    addPunto(s2, {0,2});
    Poligono sq;
    sq.secuenciadepuntos = s2;
    sq.color = Color::Verde;

    assert(getCantidadPuntos(sq.secuenciadepuntos) == 4);
    assert(areNear(getPerimetro(sq),8));
    // assert(std::fabs(getPerimetro(sq) - 8.0) < eps);

    // Test 3: polígonos con < 2 puntos -> perímetro 0
    SecuenciaDePuntos s3;
    s3.n = 0;
    Poligono p_empty;
    p_empty.secuenciadepuntos = s3;
    p_empty.color = Color::Azul;
    assert(getPerimetro(p_empty) == 0.0);

    // Test 4: Poligono de 6 lados
    SecuenciaDePuntos s4;
    s4.n = 0;
    addPunto(s4, {0,0});
    addPunto(s4, {2,0});
    addPunto(s4, {3,1});
    addPunto(s4, {2,2});
    addPunto(s4, {0,2});
    addPunto(s4, {-1,1});
    Poligono hex;
    hex.secuenciadepuntos = s4;
    hex.color = Color::Azul;
    assert(getCantidadPuntos(hex.secuenciadepuntos) == 6);
    assert(areNear(getPerimetro(hex), 9.6));
    

    // creo mis poligonos
    MisPoligonos misPoligonos;
    misPoligonos.n = 0;
    misPoligonos.a.at(misPoligonos.n++) = sq;
    misPoligonos.a.at(misPoligonos.n++) = hex;
    misPoligonos.a.at(misPoligonos.n++) = tri;
    misPoligonos.a.at(misPoligonos.n++) = p_empty; 
    MisPoligonos misPoligonosSinOrdenar = misPoligonos;

    // Ordenamiento por lados
    ordenarPorCantidadLados(misPoligonos);
    assert(getCantidadLados(misPoligonos.a.at(0)) == 0);
    assert(getCantidadLados(misPoligonos.a.at(1)) == 3);
    assert(getCantidadLados(misPoligonos.a.at(2)) == 4);
    assert(getCantidadLados(misPoligonos.a.at(3)) == 6);
    MisPoligonos misPoligonosLados = misPoligonos;

    // Ordenamiento por perímetro
    ordenarPorPerimetro(misPoligonos);
    assert(areNear(getPerimetro(misPoligonos.a.at(0)), 0.0));
    assert(areNear(getPerimetro(misPoligonos.a.at(1)), 8.0));
    assert(areNear(getPerimetro(misPoligonos.a.at(2)), 9.6));
    assert(areNear(getPerimetro(misPoligonos.a.at(3)), 12.0));
   MisPoligonos misPoligonosPerimetro = misPoligonos;

    escribirPoligonos(misPoligonosSinOrdenar, "poligonos_sin_ordenar.txt");
    escribirPoligonos(misPoligonosLados, "poligonos_ordenados.txt");
    escribirPoligonosAppend(misPoligonosPerimetro, "poligonos_ordenados.txt");
  
}

bool areNear(double a, double b, double eps)
{
    return std::fabs(a - b) < eps;
}

unsigned getCantidadLados(const Poligono& poligono)
{
    return getCantidadPuntos( poligono.secuenciadepuntos );
}

unsigned getCantidadPuntos(const SecuenciaDePuntos& s)
{
    return s.n;
}

double getPerimetro(const Poligono& p)
{
    
    if (p.secuenciadepuntos.n < 2) return 0.0;
    double perimetro {0.0};

    for (unsigned i = 0; i < p.secuenciadepuntos.n; ++i) 
    {
        perimetro += getDistanciaPuntos(p.secuenciadepuntos.a.at(i), p.secuenciadepuntos.a.at((i + 1) % p.secuenciadepuntos.n));
    }

    return perimetro;

}

double getDistanciaPuntos(const Punto& a, const Punto& b)
{
    // distancia entre puntos =  raiz( (x2 - x1)^2 + (y2 - y1)^2 )

    return std::sqrt(std::pow(b.x - a.x,2) + std::pow(b.y - a.y,2));

}

Punto leerPunto(std::ifstream& f){
    Punto p;
    f >> p.x >> p.y;
    return p;
}

void removePunto(SecuenciaDePuntos& s, Punto p)
{
    unsigned index = s.n; // índice fuera de rango
    for (unsigned i = 0; i < s.n; ++i) 
    {
        if (s.a.at(i).x == p.x && s.a.at(i).y == p.y) 
        {
            index = i;
            break;
        }
    }

    if (index == s.n) 
    {
        // punto no encontrado
        return;
    }

    // desplazar elementos a la izquierda
    for (unsigned i = index; i < s.n - 1; ++i) 
    {
        s.a.at(i) = s.a.at(i + 1);
    }
    s.n--;
}

void addPunto(SecuenciaDePuntos& s, Punto p)
{
    if (s.n >= s.a.size()) 
     {
        // fuera de rango: no agregar 
        return;
     }
    s.a.at(s.n) = p;
    s.n++;
}

Poligono crearPoligono(std::ifstream& f)
{

    Poligono p;
    SecuenciaDePuntos s;
    s.n = 0;

    unsigned count = 0;
    if (!(f >> count)) {
        // archivo mal formado -> devolver polígono vacío
        p.secuenciadepuntos = s;
        p.color = Color::Rojo;
        return p;

    }

    for (unsigned i = 0; i < count; ++i) {
        Punto pt = leerPunto(f);
        addPunto(s, pt);
    }

    int colorInt = 0;
    if (f >> colorInt) 
    {
        if (colorInt >= 0 && colorInt <= 2) 
        {
            p.color = static_cast<Color>(colorInt);
        } else 
        {
            p.color = Color::Rojo;
        }
    } else 
    {
        p.color = Color::Rojo;
    }

    p.secuenciadepuntos = s;
    return p;

}

void ordenarPorPerimetro(MisPoligonos& misPoligonos)
{
    for (unsigned i = 0; i < misPoligonos.n - 1; ++i) 
    {
        for (unsigned j = 0; j < misPoligonos.n - i - 1; ++j) 
        {
            if (getPerimetro(misPoligonos.a.at(j)) > getPerimetro(misPoligonos.a.at(j + 1))) 
            {
                std::swap(misPoligonos.a.at(j), misPoligonos.a.at(j + 1));
            }
        }
    }
}

void ordenarPorCantidadLados(MisPoligonos& misPoligonos)
{
    for (unsigned i = 0; i < misPoligonos.n - 1; ++i) 
    {
        for (unsigned j = 0; j < misPoligonos.n - i - 1; ++j) 
        {
            if (getCantidadLados(misPoligonos.a.at(j)) > getCantidadLados(misPoligonos.a.at(j + 1))) 
            {
                std::swap(misPoligonos.a.at(j), misPoligonos.a.at(j + 1));
            }
        }
    }
}


void escribirPoligonos(const MisPoligonos& misPoligonos, const std::string& filename)
{
    std::ofstream out(filename, std::ios::trunc);
    if (!out) return;

    out << "Cantidad de Poligonos: " << misPoligonos.n << '\n';
    for (unsigned i = 0; i < misPoligonos.n; ++i) {
        const Poligono& p = misPoligonos.a.at(i);
        out << "Cantidad de puntos: " << p.secuenciadepuntos.n << '\n';
        for (unsigned j = 0; j < p.secuenciadepuntos.n; ++j) {
            const Punto& pt = p.secuenciadepuntos.a.at(j);
            out << "Coordenada X: " << pt.x << " Coordenada Y: " << pt.y << '\n';
        }
        out << "Color: " << static_cast<int>(p.color) << '\n';
        out << "Fin de polígono\n";
    }
        out << "Fin de archivo\n";
    std::cout << "Polígonos escritos en " << filename << '\n';
}

void escribirPoligonosAppend(const MisPoligonos& misPoligonos, const std::string& filename)
{
    std::ofstream out(filename, std::ios::app);
    if (!out) return;

    // Al anexar, se escribe la misma estructura repetida al final
    out << "Cantidad de Poligonos: " <<misPoligonos.n << '\n';
    for (unsigned i = 0; i < misPoligonos.n; ++i) {
        const Poligono& p = misPoligonos.a.at(i);
        out << "Cantidad de puntos: " << p.secuenciadepuntos.n << '\n';
        for (unsigned j = 0; j < p.secuenciadepuntos.n; ++j) {
            const Punto& pt = p.secuenciadepuntos.a.at(j);
            out << "Coordenada X: " << pt.x << " Coordenada Y: " << pt.y << '\n';
        }
        out << "Color: " << static_cast<int>(p.color) << '\n';
        out << "Fin de polígono\n";
    }
    out << "Fin de archivo\n";
    std::cout << "Polígonos añadidos en " << filename << '\n';
}
