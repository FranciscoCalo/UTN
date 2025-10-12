#include <iostream>
#include <array>
#include <numeric> // std::accumulate

using namespace std;

/* 
============================================================
PROTOTIPOS DE FUNCIONES
============================================================ 
*/

// --- Versión con std::array ---
template<size_t M>
int sumarImportes_array(const array<int, M>& importes);

template<size_t M>
array<int, 3> ventasPorVendedor3_array(const array<array<int,2>, M>& ventas);

template<size_t N, size_t M>
array<int, N> ventasPorVendedorN_array(const array<array<int,2>, M>& ventas);

// --- Versión con int matriz[M][2] ---
int sumarImportes_c(const int importes[], int n);

array<int, 3> ventasPorVendedor3_c(const int ventas[][2], int m);

template<unsigned N>
array<int, N> ventasPorVendedorN_c(const int ventas[][2], int m);


/* 
============================================================
PROGRAMA PRINCIPAL 
============================================================ 
*/
int main() {
    cout << "===== VERSION (std::array) =====\n";
    {
        // Ejemplo 1: sumar importes
        array<int,4> importes = {100, 200, 50, 300};
        cout << "Suma de importes: " << sumarImportes_array(importes) << "\n";

        // Ejemplo 2: ventas con 3 vendedores
        array<array<int,2>,5> ventas = {{ {100,0}, {200,1}, {50,2}, {300,1}, {400,0} }};
        auto totales = ventasPorVendedor3_array(ventas);
        cout << "Ventas por vendedor (3): ";
        for (size_t i=0; i<totales.size(); i++) 
            cout << "V" << i << "=" << totales[i] << " ";
        cout << "\n";

        // Ejemplo 3: versión general con 5 vendedores
        array<array<int,2>,6> ventasN = {{{100,0}, {200,1}, {50,2}, {300,4}, {400,3}, {150,2}}};
        auto totalesN = ventasPorVendedorN_array<5>(ventasN);
        cout << "Ventas por vendedor (5): ";
        for (size_t i=0; i<totalesN.size(); i++) 
            cout << "V" << i << "=" << totalesN[i] << " ";
        cout << "\n";
    }

    cout << "\n===== VERSION (int matriz [M][2]) =====\n";
    {
        // Ejemplo 1: sumar importes
        int importes[4] = {100, 200, 50, 300};
        cout << "Suma de importes: " << sumarImportes_c(importes, 4) << "\n";

        // Ejemplo 2: ventas con 3 vendedores
        int ventas[5][2] = { {100,0}, {200,1}, {50,2}, {300,1}, {400,0} };
        auto totales = ventasPorVendedor3_c(ventas, 5);
        cout << "Ventas por vendedor (3): ";
        for (size_t i=0; i<totales.size(); i++) 
            cout << "V" << i << "=" << totales[i] << " ";
        cout << "\n";

        // Ejemplo 3: versión general con 5 vendedores
        int ventasN[6][2] = { {100,0}, {200,1}, {50,2}, {300,4}, {400,3}, {150,2} };
        auto totalesN = ventasPorVendedorN_c<5>(ventasN, 6);
        cout << "Ventas por vendedor (5): ";
        for (size_t i=0; i<totalesN.size(); i++) 
            cout << "V" << i << "=" << totalesN[i] << " ";
        cout << "\n";

    }
}


/* 
============================================================
IMPLEMENTACIÓN DE FUNCIONES
============================================================ 
*/

// -------------------------------
// Versión con std::array
// -------------------------------

// 1) Sumar importes
// ------------------------------------------------------------
// Qué hace: devuelve la suma de todos los importes.
// Situación: útil cuando los importes vienen en un std::array de tamaño fijo conocido en compilación.

template<size_t M>
int sumarImportes_array(const array<int, M>& importes) 
{
    return accumulate(importes.begin(), importes.end(), 0);
}

// 2) Ventas con 3 vendedores
// ------------------------------------------------------------
// Qué hace: devuelve un array<3> con el total vendido por cada
// vendedor (códigos 0, 1 y 2).
// Situación:  hay un número fijo (3) de categorías conocidas de antemano.

template<size_t M>
array<int, 3> ventasPorVendedor3_array(const array<array<int,2>, M>& ventas) 
{
    array<int, 3> totales{}; // inicializado en {0,0,0}
    for (auto const& par : ventas) 
    {
        int importe  = par[0];
        int vendedor = par[1];
        if (0 <= vendedor && vendedor < 3)
            totales[vendedor] += importe;
    }
    return totales;
}

// 3) Versión general para N vendedores
// ------------------------------------------------------------
// Qué hace: devuelve array<N> con totales por cada vendedor.
// Situación: cuando el número de vendedores varía y no está
// fijado en el enunciado (ej: empresa con N sucursales).

template<size_t N, size_t M>
array<int, N> ventasPorVendedorN_array(const array<array<int,2>, M>& ventas) 
{
    array<int, N> totales{}; 
    for (auto const& par : ventas) 
    {
        int importe  = par[0];
        int vendedor = par[1];
        if (0 <= vendedor && vendedor < (int)N)
            totales[vendedor] += importe;
    }
    return totales;
}


// -------------------------------
// Versión con int matriz
// -------------------------------

// 1) Sumar importes
// ------------------------------------------------------------
// Qué hace: suma todos los elementos de un arreglo clásico.
// Optimización: recorro con for; acá no conviene accumulate porque no tenemos iteradores nativos.
// Situación: arreglos de C heredados o cuando no podemos usar STL.
int sumarImportes_c(const int importes[], int n) 
{
    int suma = 0;
    for (int i=0; i<n; i++)
        suma += importes[i];
    return suma;
}

// 2) Ventas con 3 vendedores
// ------------------------------------------------------------
// Qué hace: devuelve array<3> con totales por vendedor (0-2).
// Situación: se usa con matrices C (int[][]) comunes.

array<int, 3> ventasPorVendedor3_c(const int ventas[][2], int m) {
    array<int, 3> totales{};
    for (int i=0; i<m; i++) 
    {
        int importe  = ventas[i][0];
        int vendedor = ventas[i][1];
        if (0 <= vendedor && vendedor < 3)
            totales[vendedor] += importe;
    }
    return totales;
}

// 3) Versión general para N vendedores
// ------------------------------------------------------------
// Qué hace: generaliza el caso anterior para cualquier N. 
// Situación: escenario donde el número de vendedores
// puede variar y se recibe como parámetro de plantilla.
template<unsigned N>
array<int, N> ventasPorVendedorN_c(const int ventas[][2], int m) 
{
    array<int, N> totales{};
    for (int i=0; i<m; i++) 
    {
        int importe  = ventas[i][0];
        int vendedor = ventas[i][1];
        if (0 <= vendedor && vendedor < (int)N)
            totales[vendedor] += importe;
    }
    return totales;
}