#include <cassert>

// Valor Absoluto

// abs:Z -> Z/abs(x) = |x| + raiz x ^ 2 = -x x<0 & x e.o.c (X>=0)

int abs(int);

int main(){

    assert(abs(1) == 1 );
    assert(abs (-1) == 1);
    assert(abs(0) == 0);

}

// implementacion 1

/* int abs(int x){
    return sqrt(x * x);
} */

/*
10 > 2      ?   21  :   72
condicion   ?   V   :   F 
*/

// implementacion con "?" operador condicional
int abs(int x){
    return x < 0 ? -x 
                  : x 
                  ; 
}