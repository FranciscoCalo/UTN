#include <cassert>




// espefificar, escribir las pruebas e implementar la funcion f3 definida por el grafico

// matematica
// R -> R { -3 <= x <= 3 = -x 
//            x e.o.c.          }

double f3(double);


int main(){

assert(f3(4)== 4);
assert(f3(-4)==-4);

assert(f3(3)==-3);
assert(f3(-3)==3);

assert(f3(0)==0);

assert(f3(2)==-2);
assert(f3(-2)==2);

}

double f3(double x){
    return -3 <= x and x <= 3 ? -x : x;
}
