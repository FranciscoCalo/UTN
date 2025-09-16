#include <array>
#include <cassert>


using std::array;
unsigned Minimo(const array<unsigned,10>& a);
bool areNear(double a, double b, double tol=0.1); 
void Escalar(const array<unsigned,3>& z, unsigned factor);
// primera imple
// array<unsigned,2> MaxMinProm(const array<unsigned,10>&a, double &Prom );

// segunda imple
void MaxMinProm(double &Prom, unsigned &Min, unsigned &Max, const array<unsigned,10>& a);

int main(){

// pruebas para Minimo
unsigned minimo, maximo;
double Prom;
assert(Minimo({17,25,43,49,5,6,7,8,9,10}) == 5); 
assert(Minimo({0,0,0,0,0,0,0,0,0,0}) == 0); 

// pruebas para MaxMinPRom
MaxMinProm(Prom, minimo, maximo, {17,25,43,49,5,6,7,8,9,10});
assert(minimo==5);
assert(maximo==49);
assert(areNear (Prom,17.9)); //usar arenear

// pruebas para Escalar
array<unsigned,3> vec = {1,2,3};
Escalar(vec,3);
assert(vec[0] == 3);
assert(vec[1] == 6);
assert(vec[2] == 9);

}

// primer problema encontrar minimo de un arreglo
unsigned Minimo( const array <unsigned,10>& a) 
{

    unsigned minimo{a.at(0)};
    
     for (auto e:a) //a=variable iterable  //for basado en rangos o "foreach"
    { 
       
        if(e < minimo) 
            minimo = e; 
    }

    return minimo;

}


// primera implementacion de MaxMinProm
// array<unsigned,2> MaxMinProm(const array<unsigned,10>&a, double &Prom ){

//     unsigned minimo{a.at(0)};
//     unsigned maximo{a.at(0)};
//     unsigned suma{};

//      for (auto e:a) //a=variable iterable  //for basado en rangos o "foreach"
//     { 
//         suma += e;
//         if(e > maximo) 
//             maximo = e; 
//         if(e < minimo) 
//             minimo = e; 
//     }
//     array<unsigned,2> resultados;
//     resultados.at(0) = minimo;
//     resultados.at(1) = maximo;

//     Prom = static_cast<double>(suma) / 10 ; 


// }

// segunda implementacion de MaxMinProm
void MaxMinProm(double &Prom, unsigned &Min, unsigned &Max, const array<unsigned,10>& a){

unsigned suma{};
Max = a[0];
Min = a[0];
   
     for (auto e:a)
    { 
        suma += e;
        if(e > Max) 
            Max = e; 
        if(e < Min) 
            Min = e; 
    }

    Prom = static_cast<double>(suma) / 10 ; 


}

// areNear, necesaria para comparar doubles
bool areNear(double a, double b, double tol) 
{
    return ( (a-b) < tol ) && ( (b-a) < tol ); 
}


void Escalar(array<unsigned,3>& z, unsigned factor) 
{

    for (auto &e:z) //e es una referencia a cada elemento del array
        e *= factor;
}

