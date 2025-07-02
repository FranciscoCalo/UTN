#include <iostream>

void repetirFrase(int);

int main(){

    repetirFrase(42);
}

void repetirFrase(int n){
    return (n > 0) ? (std::cout << "Voy a practicar programacion \n", repetirFrase(n - 1)) : void();
    
}