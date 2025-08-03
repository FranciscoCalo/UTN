#include <cassert>

/*
 ESPECIFICACIÓN MATEMÁTICA

1. potencia(b, e): ℕ × ℕ → ℕ
   potencia(b, e) = b^e

2. invertirNumero(n): ℕ → ℕ
   invierte los dígitos de n. Ej: invertirNumero(123) = 321

3. contarDigitos(n): ℕ → ℕ
   cuenta cuántos dígitos tiene n. Ej: contarDigitos(1234) = 4

4. sumaDigitos(n): ℕ → ℕ
   suma los dígitos de n. Ej: sumaDigitos(123) = 6

5. mcd(a, b): ℕ × ℕ → ℕ
   devuelve el máximo común divisor entre a y b (por Euclides)

6. contarPares(n): ℕ → ℕ
   cuenta cuántos números pares hay entre 1 y n (inclusive)

7. todosDigitosPares(n): ℕ → Bool
   devuelve true si todos los dígitos de n son pares

8. productoDigitos(n): ℕ → ℕ
   devuelve el producto de los dígitos de n. Ej: 123 → 1*2*3 = 6
*/

// DECLARACIÓN DE FUNCIONES 

int potencia(int, int);
int invertirNumero(int, int resultado = 0);
int contarDigitos(int);
int sumaDigitos(int);
int mcd(int, int);
int contarPares(int);
bool todosDigitosPares(int);
int productoDigitos(int);


int main() 
{
    assert(potencia(2, 4) == 16);            
    assert(invertirNumero(1234) == 4321);    
    assert(contarDigitos(9876) == 4);        
    assert(sumaDigitos(123) == 6);           
    assert(mcd(18, 24) == 6);                
    assert(contarPares(10) == 5);            
    assert(todosDigitosPares(2486) == true); 
    assert(not(todosDigitosPares(2485) == true));
    assert(productoDigitos(1234) == 24);     
}

// IMPLEMENTACIÓN DE FUNCIONES

/* 
Queremos llegar al exponente 0, que es el caso base ya que si no se detiene la recursión, se produciría un bucle infinito provocando un 
desbordamiento de pila (stack overflow).
*/

int potencia(int base, int exponente) 
{
    return (exponente == 0) ? 1 : base * potencia(base, exponente - 1);
}

/*
 Queremos llegar al caso base cuando n es 0 y devolvemos el resultado acumulado.
 En cada llamada recursiva, tomamos el último dígito de n (n % 10) y lo añadimos al resultado multiplicado por 10 para desplazar los dígitos ya invertidos a la izquierda.
 Así, al final de la recursión, tendremos el número invertido en resultado.
*/

int invertirNumero(int n, int resultado) 
{
    return (n == 0) ? resultado : invertirNumero(n / 10, resultado * 10 + n % 10);
}

/* 
 Esta función cuenta los dígitos de un número n. 
 El caso base es cuando n es menor que 10, lo que significa que solo hay un dígito.
 En caso contrario, se suma 1 al resultado de contar los dígitos del número n dividido por 10.
 Esto reduce el número en un dígito en cada llamada recursiva.
*/  

int contarDigitos(int n)
{
    return (n < 10) ? 1 : 1 + contarDigitos(n / 10);
}

/* 
 Esta función suma los dígitos de un número n. 
 El caso base es cuando n es 0, en cuyo caso la suma es 0.
 En caso contrario, se toma el último dígito (n % 10) y se suma a la suma de los dígitos del número n dividido por 10.
 Esto reduce el número en un dígito en cada llamada recursiva.
*/

int sumaDigitos(int n) 
{
    return (n == 0) ? 0 : (n % 10) + sumaDigitos(n / 10);
}

/* 
 Esta función calcula el máximo común divisor (MCD) de dos números a y b utilizando el algoritmo de Euclides.
 El caso base es cuando b es 0, en cuyo caso el MCD es a.
 En caso contrario, se llama recursivamente con b y el resto de la división de a entre b.
 Esto reduce el problema hasta que se alcanza el caso base.
*/

int mcd(int a, int b) 
{
    return (b == 0) ? a : mcd(b, a % b);
}

/*
 Esta función cuenta cuántos números pares hay entre 1 y n (inclusive).
 El caso base es cuando n es 0, en cuyo caso no hay números pares.
 En caso contrario, se verifica si n es par (n % 2 == 0) y se suma 1 si lo es, o 0 si no lo es, y se llama recursivamente con n - 1.
 Esto reduce el problema hasta que se alcanza el caso base.
*/

int contarPares(int n) 
{
    return (n == 0) ? 0 : ((n % 2 == 0) ? 1 : 0) + contarPares(n - 1);
}

/* 
 Esta función verifica si todos los dígitos de un número n son pares.
 El caso base es cuando n es 0, en cuyo caso se considera que todos los dígitos son pares.
 En caso contrario, se verifica si el último dígito (n % 10) es par (n % 2 == 0).
 Si lo es, se llama recursivamente con el número n dividido por 10; de lo contrario, se devuelve false.
 Esto reduce el número en un dígito en cada llamada recursiva.
*/

bool todosDigitosPares(int n) 
{
    return (n == 0) ? true : ((n % 2 == 0) ? todosDigitosPares(n / 10) : false);
}

int productoDigitos(int n) 
{
    return (n < 10) ? n : (n % 10) * productoDigitos(n / 10);
}
