// Especificacion matematica 

// dado un vector que puede recibir por parametro, de ese vector sacar el promedio de los valores
// dado un vector, hay que encontrar el máximo de todos los elementos

// Estadistica : N^n -> N^2 / Vectores: 

#include <array>
#include <cassert>

// Prototipo

using std:: array;

array<unsigned,2> Estadistica(const array<unsigned,10>& a);

// Pruebas

int main() 
{
    // primera implementacion
    array<unsigned,10> vec = {1,2,3,4,5,6,7,8,9,10}; //vec: variable local
    array<unsigned,2> resultados = Estadistica(vec);
    
    assert(resultados[0] == 5); // promedio
    assert((resultados[1]) == 10); // maximo
    
    // segunda implementacion ----------------------
    //assert(Estadistica({1,2,3,4,5,6,7,8,9,10}) == {5,10}); // promedio
    assert(Estadistica({1,2,3,4,5,6,7,8,9,10}).at(0) == 5); // promedio
    assert(Estadistica({1,2,3,4,5,6,7,8,9,10}).at(1) == 10); // maximo
    
    //assert(Estadistica({1,2,3,4,5,6,7,8,9,10})[10] != 0); // no sabemos que puede pasar, para forzar el uso del corchete

    }

// array<unsigned,2> Estadistica(array<unsigned,10> a) 


    // unsigned suma{};
    
    // array<unsigned,2> resultados;
    // // parte 1 hacer una suma de los elementos del vector y dividirlo por la cantidad de elementos para sacar el promedio
    // for (unsigned i = 0; i < 10; ++i) 
    //     suma += a.at(i);     
    
    
    // // parte 2 encontrar el maximo de todos los elementos del vector
    
    // unsigned maximo{};
    
    // for(unsigned i = 0; i < 10; ++i) 
    //     if(a.at(i) > maximo) 
    //     maximo = a.at(i);


    // resultados.at(0) = suma / 10;
    // resultados.at(1) = maximo;


array<unsigned,2> Estadistica(array<unsigned,10>& a) 
{
    unsigned suma{};
    unsigned maximo{};
    
    
// // implementacion todo en uno 
//     for anterior 
//    for (unsigned i = 0; i < 10; ++i) 
//     { 
//         suma += a.at(i);    
//         if(a.at(i) > maximo) 
//             maximo = a.at(i); 
//     }
//     
    
     for (auto e:a) //a=variable iterable  //for basado en rangos o "foreach"
    { 
        suma += e;   
        if(e > maximo) 
            maximo = e; 
    }
    array<unsigned,2> resultados;
    resultados.at(0) = suma / 10;
    resultados.at(1) = maximo;


    return resultados;

}
   






