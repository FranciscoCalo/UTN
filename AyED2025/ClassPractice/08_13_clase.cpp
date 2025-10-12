#include <cassert>

unsigned SumaR (unsigned);
unsigned SumaI (unsigned);
unsigned SumaF (unsigned);

int main (){



}


unsigned SumaR (unsigned n){

    return (n == 0) ? 0 : n + SumaR(n - 1);

}

unsigned SumaI (unsigned n){

unsigned s {0}; // iniciamos las variables con { 0 } , tambien se puede usar { }, las variables numericas "vacias" se inician en 0.


for (unsigned i {0} ;       i <= n ;                         ++i )
     // 1 sola vez ; al principio de cada vuelta ; al final de cada vuelta
     s = s + i;
     // s+=i;
// el for no tiene las llaves porque repite una sentencia nomas.
}

unsigned SumaF (unsigned n) {

    return (n * (n + 1)) / 2;

}