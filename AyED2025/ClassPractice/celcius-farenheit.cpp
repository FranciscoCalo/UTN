#include <cassert>

/*Matematica:
F: R -> R / F(c) = c * 9/5 + 32
C: R -> R / C(f) = (f - 32) * 5/9

*/


double celciusToFarenheit(double);
double farenheitToCelcius(double);


int main() {

    assert(celciusToFarenheit(0) == 32);
    assert(celciusToFarenheit(100) == 212);
    assert(celciusToFarenheit(-40) == -40);
    
    assert(farenheitToCelcius(32) == 0);
    assert(farenheitToCelcius(212) == 100);
    assert(farenheitToCelcius(-40) == -40);
    
}


double celciusToFarenheit(double celcius) {
    return (celcius * 9.0 / 5.0 + 32);
}

double farenheitToCelcius(double farenheit) {
    return ((farenheit - 32) * 5.0 / 9.0);
} 