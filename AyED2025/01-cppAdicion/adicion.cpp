#include <iostream>

int main(){

    // Se declaran las variables a y b como enteros
    int a, b;
    
    // Se solicita al usuario que ingrese dos números enteros y se almacenan en las variables a y b
    std::cout<< "Ingresar primer numero entero a sumar:";
    std::cin>> a;
    std::cout<< "Ingresar segundo numero entero a sumar:";
    std::cin>> b;

    // Se imprime la suma de a y b en la consola
    std::cout<< "La suma de " << a << " + " << b << " es: " << a + b;
    
}