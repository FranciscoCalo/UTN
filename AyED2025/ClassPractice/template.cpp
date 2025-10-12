template<unsigned N>
void escalar (array <unsigned, N> &v, unsigned f){
    for (auto &e:v)
        e*=f;
};
