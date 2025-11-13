#include <iostream>
#include <fstream>
#include <array>

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

double getPerimetro(const Poligono&){

}

double getDistanciaPuntos(const Punto&, const Punto&){

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

}