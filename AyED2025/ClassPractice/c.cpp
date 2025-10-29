#include <string>
#include <cassert>


struct Punto{
    int x;
    int y;
};

std::string ubicacion (Punto p);

int main(){

assert(ubicacion({0,0}) == "origen");
assert(ubicacion({0,5}) == "eje Y");
assert(ubicacion({5,0}) == "eje X");
assert(ubicacion({5,5}) == "cuadrante 1");
assert(ubicacion({-5,5}) == "cuadrante 2");
assert(ubicacion({-5,-5}) == "cuadrante 3");
assert(ubicacion({5,-5}) == "cuadrante 4");


}



std::string ubicacion (Punto p){
    return p.x == 0 && p.y == 0? "origen" : p.x == 0? "eje Y" : p.y == 0? "eje X" : p.x > 0 && p.y > 0? "cuadrante 1" : p.x < 0 && p.y > 0? "cuadrante 2" : p.x < 0 && p.y < 0? "cuadrante 3" : "cuadrante 4";

}