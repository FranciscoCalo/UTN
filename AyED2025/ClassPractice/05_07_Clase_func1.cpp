#include <iostream>
#include <cassert>

double f(double);

int main() {

std::cout << f(3);
assert (2 * 3 + 1 == 7);
assert (7 == f(3));


}

double f(double x){ return 2 * x + 1;}