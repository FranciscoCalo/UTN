#include <array>
#include <cassert>


using std::array;
bool areNear(double a, double b, double tol=0.1); 
void Escalar(array<unsigned,3>& z, unsigned factor);

int main(){

// pruenas para escalar

}


void Escalar(array<unsigned,3>& z, unsigned factor) 
{

    for (auto &e:z) //e es una referencia a cada elemento del array
        e *= factor;
}

