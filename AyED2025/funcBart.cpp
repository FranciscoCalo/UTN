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

void frase1(unsigned , std::string);
std::string frase2(unsigned , std::string);

std::string repetirFrase1(unsigned);
void repetirFrase2(unsigned);

int main(){

    // std::cout << repetirFrase1(2);
    // std::cout << "\n";
    // repetirFrase2(2);

    frase1(2, "bart");
    std::cout << "\n";
    std::cout << frase2(2, "bart");

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

void frase1(const unsigned n, const std::string s){

for (unsigned i {}; i < n ; ++i)

    std::cout << s << "\n";

}

std::string frase2(const unsigned n, const std::string s){
    std::string r{};

    for (unsigned i {}; i < n ; ++i)

     r = r + s + "\n";

    return r;
 
}