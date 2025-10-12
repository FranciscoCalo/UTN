#include <cassert>
#include <iostream>

double Celsius(double);
bool AreNear(double, double, double = 0.001);

int main(){

    assert( 0 == Celsius (32) );
    std::cout << Celsius(64); // 17.7778
    assert( 17.7778 != Celsius(64));

}

double Celsius(double f){return 5.0/9.0*(f-32);}
bool AreNear(double a, double b, double delta){
    return (a-delta) <= b and b <= (a+delta);
}