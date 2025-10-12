#include <cassert>
#include <iostream> 
#include <cstdio> // se usa para funciones de entrada/salida como fprintf, FILE* y _open que permite enviar datos y comandos a gnuplot


/* Implementacion Matematica:
F: R -> R / F(c) = c * 9/5 + 32
C: R -> R / C(f) = (f - 32) * 5/9

*/

/*Definicion de funciones*/
double celciusToFarenheit(double);
double farenheitToCelcius(double);
bool AreNear(double, double, double = 0.001);


int main() {

    assert(celciusToFarenheit(0) == 32);
    assert(celciusToFarenheit(100) == 212);
    assert(celciusToFarenheit(-40) == -40);
    
    assert(farenheitToCelcius(32) == 0);
    assert(farenheitToCelcius(212) == 100);
    assert(farenheitToCelcius(-40) == -40);
    

    // Crear una tabla con valores de celcius y farenheit -60C a 120C con incremento de 10C
    std::cout << "Celcius\tFarenheit\n";
    for (int i = -60; i <= 120; i += 10) {
        std::cout << i << "\t" << celciusToFarenheit(i) << "\n";
    }

    // agregar tabla inversa farenheit to celcius.

    // Para graficar los datos, se usa gnuplot
    // Asegurarse de que gnuplot este instalado y en el PATH del sistema
    
   /* FILE* gnuplotPipe = _popen("gnuplot -persistent", "w"); // abrir gnuplot en modo escritura, como si escribiera en la consola gnuplot

    if (gnuplotPipe) { // Si se pudo abrir gnuplot
        // Se envian los comandos a gnuplot para graficar
        fprintf(gnuplotPipe, "set title 'Celsius <-> Fahrenheit'\n");
        fprintf(gnuplotPipe, "set xlabel 'Celsius'\n");
        fprintf(gnuplotPipe, "set ylabel 'Fahrenheit'\n");
        // El comando 'plot' se usa para graficar dos funciones
        fprintf(gnuplotPipe, "plot '-' with lines title 'F = C*9/5+32','-' with lines title 'C = (F-32)*5/9'\n");
        // Se envian datos para Celsius a Fahrenheit
        for (int i = -60; i <= 120; i += 10) {
            fprintf(gnuplotPipe, "%d %f\n", i, celciusToFarenheit(i));
        }
        fprintf(gnuplotPipe, "e\n"); // 'e\n' indica el final de los datos para la primera funcion
        // Se envian datos para Fahrenheit a Celsius
        for (int i = -60; i <= 120; i += 10) {
            fprintf(gnuplotPipe, "%d %f\n", i, farenheitToCelcius(i));
        }
        fprintf(gnuplotPipe, "e\n");

        fflush(gnuplotPipe); // Asegurarse de que los datos se envien a gnuplot
        _pclose(gnuplotPipe); // Cerrar el pipe de gnuplot
    } else {
        std::cerr << "No se pudo abrir gnuplot.\n";
    }
 */   
}

/* Implementacion de funciones*/
double celciusToFarenheit(double celcius) {
    return (celcius * 9.0 / 5.0 + 32);
}

double farenheitToCelcius(double farenheit) {
    return ((farenheit - 32) * 5.0 / 9.0);
} 

bool AreNear(double a, double b, double delta){
    return (a-delta) <= b and b <= (a+delta);
}