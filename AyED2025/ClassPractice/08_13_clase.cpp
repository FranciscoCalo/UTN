#include <cassert>

unsigned Suma (unsigned);

int main (){



}


unsigned Suma (unsigned n){

unsigned s {0};

for (unsigned i {0} ;       i <= n ;                         ++i )
     // 1 sola vez ; al principio de cada vuelta ; al final de cada vuelta
     s = s + i;
     // s+=i;
// el for no tiene las llaves porque repite una sentencia nomas.



}