#include <iostream>  // Incluye la biblioteca estándar para entrada/salida en consola (cout, cin, etc.).
#include <fstream>   // Incluye la biblioteca para operaciones con archivos (ofstream para escribir en archivos).
#include <array>     // Incluye la biblioteca para usar contenedores array de tamaño fijo.
#include <sstream>   // Incluye la biblioteca para manipular streams de strings (stringstream para construir cadenas).
#include <iomanip>   // Incluye la biblioteca para formateo de salida (setw, right, etc.).
#include <random>    // Incluye la biblioteca para generación de números aleatorios (random_device, mt19937, distribuciones).
using namespace std; // Declara el uso del espacio de nombres std para evitar escribir std:: en cada uso de elementos estándar.

// Prototipos de funciones: Declara las funciones antes de main para que el compilador las conozca.
void generarArchivoTotalVentas(istream& flujo, const string& nombreArchivo);  // Prototipo: Función para generar archivo de total de ventas (0 dimensiones: escalar).
void generarArchivoVentasPorMes(istream& flujo, const string& nombreArchivo);  // Prototipo: Función para generar archivo de ventas por mes (1 dimensión: array por mes).
void generarArchivoVentasPorMesYVendedor(istream& flujo, const string& nombreArchivo);  // Prototipo: Función para generar archivo de ventas por mes y vendedor (2 dimensiones: array por mes y vendedor).
void generarArchivoVentasPorMesVendedorRegion(istream& flujo, const string& nombreArchivo);  // Prototipo: Función para generar archivo de ventas por mes, vendedor y región (3 dimensiones: array por mes, vendedor y región).

const int ANCHO_IMPORTE = 15;  // Define una constante para el ancho fijo de los campos de importes en la salida formateada.

int main() {  // Función principal del programa, punto de entrada.
    const int cantidadRegistros = 200;  // Define una constante para el número de registros de datos a generar (200 ventas).
    stringstream flujoDatos;  // Crea un stringstream para construir los datos de ventas como una cadena.

    flujoDatos << cantidadRegistros << "\n";  // Escribe el número de registros en el stringstream, seguido de un salto de línea.

    random_device rd;  // Crea un objeto random_device para obtener una semilla aleatoria del hardware.
    mt19937 gen(rd());  // Crea un generador de números pseudoaleatorios Mersenne Twister inicializado con la semilla de rd.

    // Distribución normal para importes: Define una distribución normal para generar importes con media 5000 y desviación 2000.
    normal_distribution<double> distImporte(5000.0, 2000.0);
    // Distribuciones uniformes para otras variables: Define distribuciones uniformes para mes (0-11), vendedor (0-2) y región (0-3).
    uniform_int_distribution<int> distMes(0, 11);  // Distribución uniforme para meses (0 a 11, representando enero a diciembre).
    uniform_int_distribution<int> distVendedor(0, 2);  // Distribución uniforme para vendedores (0 a 2, tres vendedores).
    uniform_int_distribution<int> distRegion(0, 3);  // Distribución uniforme para regiones (0 a 3, cuatro regiones).

    for (int i = 0; i < cantidadRegistros; i++) {  // Bucle for para generar 200 registros de datos.
        int importe = (int)distImporte(gen);  // Genera un importe aleatorio de la distribución normal y lo convierte a entero.
        if (importe < 100) importe = 100;  // Asegura que el importe no sea menor a 100, ajustándolo si es necesario.
        if (importe > 20000) importe = 20000;  // Asegura que el importe no sea mayor a 20000, ajustándolo si es necesario.

        int mes = distMes(gen);  // Genera un mes aleatorio (0-11).
        int vendedor = distVendedor(gen);  // Genera un vendedor aleatorio (0-2).
        int region = distRegion(gen);  // Genera una región aleatoria (0-3).

        flujoDatos << importe << " " << mes << " " << vendedor << " " << region << "\n";  // Escribe el registro completo (importe, mes, vendedor, región) en el stringstream.
    }

    string datos = flujoDatos.str();  // Convierte el contenido del stringstream en una cadena de texto (todos los datos generados).
    stringstream flujo1(datos), flujo2(datos), flujo3(datos), flujo4(datos);  // Crea cuatro stringstreams independientes, cada uno con una copia de los datos para procesar en paralelo sin interferencias.

    generarArchivoTotalVentas(flujo1, "Dim0.txt");  // Llama a la función para generar el archivo de total de ventas usando flujo1 (0 dimensiones).
    generarArchivoVentasPorMes(flujo2, "Dim1.txt");  // Llama a la función para generar el archivo de ventas por mes usando flujo2 (1 dimensión).
    generarArchivoVentasPorMesYVendedor(flujo3, "Dim2.txt");  // Llama a la función para generar el archivo de ventas por mes y vendedor usando flujo3 (2 dimensiones).
    generarArchivoVentasPorMesVendedorRegion(flujo4, "Dim3.txt");  // Llama a la función para generar el archivo de ventas por mes, vendedor y región usando flujo4 (3 dimensiones).

    cout << "Archivos generados correctamente.\n";  // Imprime un mensaje de confirmación en la consola.
    return 0;  // Retorna 0 para indicar que el programa terminó exitosamente.
}

// ------ NECESIDAD #1: Total ventas (0 dimensiones: solo un escalar para el total general) ------
void generarArchivoTotalVentas(istream& flujo, const string& nombreArchivo) {  // Define la función para generar el archivo de total de ventas, recibiendo un flujo de entrada y el nombre del archivo.
    ofstream archivo(nombreArchivo);  // Crea un objeto ofstream para escribir en el archivo especificado.
    int n;  // Declara una variable para almacenar el número de registros.
    flujo >> n;  // Lee el número de registros desde el flujo de entrada.

    int total = 0, importe, mes, vendedor, region;  // Inicializa el total en 0 (escalar de 0 dimensiones) y declara variables para importe, mes, vendedor y región.
    for (int i = 0; i < n; i++) {  // Bucle for para leer y sumar n registros.
        flujo >> importe >> mes >> vendedor >> region;  // Lee un registro completo desde el flujo (importe, mes, vendedor, región).
        total += importe;  // Acumula el importe en el total general (sin array, solo suma escalar).
    }

    archivo << "------ NECESIDAD #1: TOTAL VENTAS ------\n";  // Escribe el encabezado de la necesidad en el archivo.
    archivo << "Total de ventas = $" << total << "\n";  // Escribe el total calculado en el archivo, formateado con $.
}

// ------ NECESIDAD #2: Ventas por mes (1 dimensión: array para acumular por mes) ------
void generarArchivoVentasPorMes(istream& flujo, const string& nombreArchivo) {  // Define la función para generar el archivo de ventas por mes.
    ofstream archivo(nombreArchivo);  // Crea un objeto ofstream para escribir en el archivo.
    int n;  // Declara variable para el número de registros.
    flujo >> n;  // Lee el número de registros desde el flujo.

    array<int, 12> ventasMes{};  // Crea un array de 1 dimensión (12 elementos) inicializados en 0 para acumular ventas por mes (índices 0-11).
    int importe, mes, vendedor, region;  // Declara variables para leer cada registro.

    for (int i = 0; i < n; i++) {  // Bucle for para procesar n registros.
        flujo >> importe >> mes >> vendedor >> region;  // Lee un registro completo.
        ventasMes.at(mes) += importe;  // Acumula el importe en el array de 1D correspondiente al mes, usando .at() para acceso seguro con verificación de límites.
    }

    archivo << "------ NECESIDAD #2: VENTAS POR MES ------\n";  // Escribe el encabezado en el archivo.
    archivo << "+-----+-----------------+\n";  // Escribe la línea superior de la tabla.
    archivo << "| Mes |   Importe ($)   |\n";  // Escribe el encabezado de columnas de la tabla.
    archivo << "+-----+-----------------+\n";  // Escribe la línea separadora de la tabla.

    int total = 0;  // Inicializa una variable para el total general (escalar).
    for (int i = 0; i < 12; i++) {  // Bucle for para escribir cada mes (0-11).
        archivo << "| " << setw(3) << i << " | $"  // Escribe el mes con ancho fijo de 3 caracteres.
                << setw(ANCHO_IMPORTE - 1) << right << ventasMes.at(i) << " |\n";  // Escribe el importe alineado a la derecha con ancho fijo, usando .at() para acceso seguro en el array de 1D, seguido de | y salto de línea.
        total += ventasMes.at(i);  // Acumula el importe en el total, usando .at() para acceso seguro en el array de 1D.
    }

    archivo << "+-----+-----------------+\n";  // Escribe la línea inferior de la tabla.
    archivo << "Total ventas = $" << total << "\n";  // Escribe el total general al final.
}

// ------ NECESIDAD #3: Ventas por mes y vendedor (2 dimensiones: array para mes y vendedor) ------
void generarArchivoVentasPorMesYVendedor(istream& flujo, const string& nombreArchivo) {  // Define la función para generar el archivo de ventas por mes y vendedor.
    ofstream archivo(nombreArchivo);  // Crea un objeto ofstream para escribir en el archivo.
    int n;  // Declara variable para el número de registros.
    flujo >> n;  // Lee el número de registros.

    array<array<int, 3>, 12> ventasMesVendedor{};  // Crea un array de 2 dimensiones usando std::array anidado: 12 meses x 3 vendedores, inicializado en 0.
    int importe, mes, vendedor, region;  // Declara variables para leer registros.

    for (int i = 0; i < n; i++) {  // Bucle for para procesar n registros.
        flujo >> importe >> mes >> vendedor >> region;  // Lee un registro completo.
        ventasMesVendedor.at(mes).at(vendedor) += importe;  // Acumula el importe en la celda del array de 2D correspondiente a mes y vendedor, usando .at() para accesos seguros con verificación de límites.
    }

    archivo << "------ NECESIDAD #3: VENTAS POR MES Y VENDEDOR ------\n";  // Escribe el encabezado.
    archivo << "+-----+-----------------+-----------------+-----------------+\n";  // Línea superior de la tabla.
    archivo << "| Mes |   Vendedor 0    |   Vendedor 1    |   Vendedor 2    |\n";  // Encabezado de columnas.
    archivo << "+-----+-----------------+-----------------+-----------------+\n";  // Línea separadora.

    array<int, 3> totales{};  // Crea un array de 1D (3 elementos) inicializados en 0 para totales por vendedor.
    for (int i = 0; i < 12; i++) {  // Bucle for para cada mes.
        archivo << "| " << setw(3) << i << " ";  // Escribe el mes con ancho fijo.
        for (int v = 0; v < 3; v++) {  // Bucle anidado para cada vendedor (0-2).
            archivo << "| $" << setw(ANCHO_IMPORTE - 1) << right << ventasMesVendedor.at(i).at(v) << " ";  // Escribe el importe por vendedor con formato, usando .at() para accesos seguros en el array de 2D.
            totales.at(v) += ventasMesVendedor.at(i).at(v);  // Acumula en el total por vendedor, usando .at() para accesos seguros en arrays de 1D y 2D.
        }
        archivo << "|\n";  // Cierra la fila de la tabla.
    }

    archivo << "+-----+-----------------+-----------------+-----------------+\n";  // Línea inferior de la tabla.
    for (int v = 0; v < 3; v++) {  // Bucle para escribir totales por vendedor.
        archivo << "Total Vendedor " << v << ": $" << totales.at(v) << "\n";  // Escribe cada total, usando .at() para acceso seguro en el array de 1D.
    }
}

// ------ NECESIDAD #4: Ventas por mes, vendedor y región (3 dimensiones: array para mes, vendedor y región) ------
void generarArchivoVentasPorMesVendedorRegion(istream& flujo, const string& nombreArchivo) {  // Define la función para generar el archivo detallado.
    ofstream archivo(nombreArchivo);  // Crea un objeto ofstream para escribir en el archivo.
    int n;  // Declara variable para el número de registros.
    flujo >> n;  // Lee el número de registros.

    array<array<array<int, 4>, 3>, 12> ventas{};  // Crea un array de 3 dimensiones usando std::array anidado: 12 meses x 3 vendedores x 4 regiones, inicializado en 0.
    int importe, mes, vendedor, region;  // Declara variables para leer registros.

    for (int i = 0; i < n; i++) {  // Bucle for para procesar n registros.
        flujo >> importe >> mes >> vendedor >> region;  // Lee un registro completo.
        ventas.at(mes).at(vendedor).at(region) += importe;  // Acumula el importe en la celda del array de 3D correspondiente a mes, vendedor y región, usando .at() para accesos seguros con verificación de límites.
    }

    archivo << "------ NECESIDAD #4: VENTAS POR MES, VENDEDOR Y REGIÓN ------\n";  // Escribe el encabezado.
    archivo << "+-----+-----------+-----------------+-----------------+-----------------+-----------------+\n";  // Línea superior de la tabla.
    archivo << "| Mes | Vendedor  |    Región 0     |    Región 1     |    Región 2     |    Región 3     |\n";  // Encabezado de columnas.
    archivo << "+-----+-----------+-----------------+-----------------+-----------------+-----------------+\n";  // Línea separadora.

    array<int, 3> totalesVendedor{};  // Array de 1D para totales por vendedor (3 elementos, inicializados en 0).
    array<int, 4> totalesRegion{};  // Array de 1D para totales por región (4 elementos, inicializados en 0).

    for (int m = 0; m < 12; m++) {  // Bucle externo para cada mes.
        for (int v = 0; v < 3; v++) {  // Bucle anidado para cada vendedor.
            archivo << "| " << setw(3) << m << " | " << setw(9) << v << " ";  // Escribe mes y vendedor con formatos fijos.
            for (int r = 0; r < 4; r++) {  // Bucle anidado para cada región.
                archivo << "| $" << setw(ANCHO_IMPORTE - 1) << right << ventas.at(m).at(v).at(r) << " ";  // Escribe el importe por región con formato, usando .at() para accesos seguros en el array de 3D.
                totalesVendedor.at(v) += ventas.at(m).at(v).at(r);  // Acumula en total por vendedor, usando .at() para accesos seguros en arrays de 1D y 3D.
                totalesRegion.at(r) += ventas.at(m).at(v).at(r);  // Acumula en total por región, usando .at() para accesos seguros en arrays de 1D y 3D.
            }
            archivo << "|\n";  // Cierra la fila.
        }
        archivo << "+-----+-----------+-----------------+-----------------+-----------------+-----------------+\n";  // Línea separadora después de cada mes.
    }

    archivo << "Totales por vendedor:\n";  // Escribe encabezado para totales por vendedor.
    for (int v = 0; v < 3; v++) {  // Bucle para escribir totales por vendedor.
        archivo << "Vendedor " << v << ": $" << totalesVendedor.at(v) << "\n";  // Escribe cada total, usando .at() para acceso seguro.
    }

    archivo << "\nTotales por región:\n";  // Escribe encabezado para totales por región con salto de línea.
    for (int r = 0; r < 4; r++) {  // Bucle para escribir totales por región.
        archivo << "Región " << r << ": $" << totalesRegion.at(r) << "\n";  // Escribe cada total, usando .at() para acceso seguro.
    }
}
