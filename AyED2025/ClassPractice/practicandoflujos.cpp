#include <iostream>  // Incluye la biblioteca estándar para entrada/salida en consola (cout, cin, etc.).
#include <fstream>   // Incluye la biblioteca para operaciones con archivos (ofstream para escribir en archivos).
#include <array>     // Incluye la biblioteca para usar contenedores array de tamaño fijo.
#include <sstream>   // Incluye la biblioteca para manipular streams de strings (stringstream para construir cadenas).
#include <iomanip>   // Incluye la biblioteca para formateo de salida (setw, right, etc.).
#include <random>    // Incluye la biblioteca para generación de números aleatorios (random_device, mt19937, distribuciones).
using namespace std; // Declara el uso del espacio de nombres std para evitar escribir std:: en cada uso de elementos estándar.

int main (){

    stringstream flujoDatos;  // Crea un stringstream para construir los datos de ventas como una cadena.

    flujoDatos << 500 << " " << 299 << " " << 399 << "\n";

    int saco, saco2 {};

    flujoDatos >> saco >> saco2;
    
    string flujo1 = flujoDatos.str();

    cout << saco << "\n";

    cout << "-----------" << "\n";

    flujoDatos >> saco2 ;

    string flujo2 = flujoDatos.str();

    cout << saco2 << "\n";

    struct GuardarCurso2D{
        string curso;
        array <int,2> punto; 

    };

    GuardarCurso2D MiVariable;

    MiVariable.curso = "K1053";
    MiVariable.punto.at(0) = 4;
    MiVariable.punto.at(1) = 5;




}