#include <cassert>

// PROBLEMA: Especificar e implementar doble(n)

// Especificacion: double: Z -> Z / double(n) = 2 * n

int Double(int); // Declaración de la función

int main() {

assert ( -14 == double(-7) ); // Prueba de la función negativos
assert ( 0 == double(0) ); // Prueba de la función cero
assert ( 42 == double(21) ); // Prueba de la función positivos

}

int Double(int n) { return 2 * n; } // Implementación de la función