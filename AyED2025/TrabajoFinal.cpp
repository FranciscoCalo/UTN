#include <iostream>
#include <fstream>
#include <array>
#include <cmath>

struct Punto{int x,y; };
struct SecuenciaDePuntos{
    std::array<Punto, 100> a;
    unsigned n;
};
enum struct Color { Rojo, Verde, Azul };
struct Poligono{
    SecuenciaDePuntos secuenciadepuntos;
    Color color;
};

unsigned getCantidadLados(const Poligono&);
unsigned getCantidadPuntos(const SecuenciaDePuntos&);
double getPerimetro(const Poligono&);
double getDistanciaPuntos(const Punto&, const Punto&);
Punto leerPunto(std::ifstream&);
void addPunto(SecuenciaDePuntos&, Punto);
Poligono crearPoligono(std::ifstream&);

int main() {
 


}


unsigned getCantidadLados(const Poligono& poligono){
    return getCantidadPuntos( poligono.secuenciadepuntos );
}

unsigned getCantidadPuntos(const SecuenciaDePuntos& s){
    return s.n;
}

double getPerimetro(const Poligono& p){
    double perimetro;

    for (int i{0}; i< p.secuenciadepuntos.n;i++)
    perimetro =+ getDistanciaPuntos(p.secuenciadepuntos.a.at(i),p.secuenciadepuntos.a.at(i+1)); // sumar la distancia entre punto anterior y punto a perimetro

    return perimetro;

}

double getDistanciaPuntos(const Punto& a, const Punto& b){

    double distancia;

    return distancia = std::sqrt(std::pow(b.x-a.x,2)+ std::pow(b.y-a.y,2));

}

Punto leerPunto(std::ifstream& f){
    Punto p;
    f >> p.x >> p.y;
    return p;
}

void addPunto(SecuenciaDePuntos& s, Punto p){
    s.a.at(s.n) = p;
    s.n++;
}

Poligono crearPoligono(std::ifstream& f){

    Poligono p;
    SecuenciaDePuntos s;
    addPunto(s,leerPunto(f));
    return p;

}