#include <iostream>
#include <string>
/*

Implementacion 1: frase: Z -> E*
Frase(2)= "bart.bart"

int main (){

    cout << frase(42);
    }

Implementacion 2: frase: Z -> { }

Frase(2)

int main(){
    Frase(42);]\
    }

*/


std::string repetirFrase1(unsigned);
void repetirFrase2(unsigned);

int main(){

    std::cout << repetirFrase1(2);
    std::cout << "\n";
    repetirFrase2(2);
}

std::string repetirFrase1 (unsigned n){
    return (n > 0) ? "Voy a practicar programacion \n" + repetirFrase1(n - 1) : "" ;
}

void repetirFrase2(unsigned n){
    if(n > 0){
        std::cout << "Voy a practicar programacion \n";
        repetirFrase2(n - 1);
    }
}