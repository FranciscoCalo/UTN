
#include <algorithm> // Para std::swap
#include <cstring> 
#include <iostream>
#include <cassert>

// declaracion de funciones
unsigned factorial(unsigned n);
unsigned sumaNaturales(unsigned n);
unsigned fibonacci(unsigned n);
void invertirCadena(char* str, int inicio, int fin);
bool esPalindromo(const char* str, int inicio, int fin);

int main(){

    // Ejemplos de uso de las funciones
  
    assert(factorial(5) == 120);
    assert(sumaNaturales(5) == 15);
    assert(fibonacci(5) == 5);

    char originalStr[] = "radar";
    char invertedStr[] = "radar";
    invertirCadena(invertedStr, 0, strlen(invertedStr) - 1);
    // "radar" invertido es "radar" (palíndromo)
    assert(strcmp(invertedStr, "radar") == 0);

    assert(esPalindromo(originalStr, 0, strlen(originalStr) - 1) == true);

    return 0;
}


// Factorial de un número n (n!)
unsigned factorial(unsigned n) {
    return (n == 0) ? 1 : n * factorial(n - 1);
}

// Suma de los primeros n números naturales
unsigned sumaNaturales(unsigned n) {
    return (n == 0) ? 0 : n + sumaNaturales(n - 1);
}

// Fibonacci (n-ésimo término)
unsigned fibonacci(unsigned n) {
    return (n <= 1) ? n : fibonacci(n - 1) + fibonacci(n - 2);
}

// Invertir una cadena de caracteres recursivamente
void invertirCadena(char* str, int inicio, int fin) {
    if (inicio < fin) {
        std::swap(str[inicio], str[fin]);
        invertirCadena(str, inicio + 1, fin - 1);
    }
}

// Comprobar si una cadena es palíndromo recursivamente
bool esPalindromo(const char* str, int inicio, int fin) {
    if (inicio >= fin) return true;
    if (str[inicio] != str[fin]) return false;
    return esPalindromo(str, inicio + 1, fin - 1);
}