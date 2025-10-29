#include <array>
#include <cassert>


struct estado{
    int posicion;
    bool encontro;
};

template<std::size_t M>
estado buscar (const std::array<int,M>& secuencia, int buscado );
template<std::size_t M>
int buscar2(const std::array<int,M>& secuencia, int buscado , bool& encontrado );
template<std::size_t M>
bool buscar3 (const std::array<int,M>& secuencia, int buscado, unsigned& posicion );

int main(){

std::array <int,5> a {7,4,9,42,9};
unsigned pos;

assert(buscar3(a,4,pos)and pos == 1);
assert(not buscar3(a,77,pos));




}

template<std::size_t M>
estado buscar(const std::array<int,M>& secuencia, int buscado){
    for (std::size_t i = 0; i < M; ++i){
        if (secuencia[i] == buscado){
            return {static_cast<int>(i), true};
        }
    }
    return {-1, false};
}







template<std::size_t M>
bool buscar3(const std::array<int,M>& secuencia, int buscado, unsigned& posicion){
    for (int i {0}; i < secuencia.size(); ++i){
        if (secuencia.at(i) == buscado){
            posicion = i;
            return true;
        }
    }
    return false;
}