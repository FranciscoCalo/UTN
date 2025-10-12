#include <cassert>

enum struct PuntoCardinal {
    Norte,
    Sur,
    Este,
    Oeste,
};


using enum PuntoCardinal;

int main(){

PuntoCardinal orientacion { Norte };
assert (orientacion == Norte);
orientacion = Sur;

}