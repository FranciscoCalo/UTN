#include <cassert>

/* F(x) =   | 3     x < 4
                | x-1   4 <= x < 7
                    | 6     7 < x < 11
                    | x-5   11 <= x
    
*/
double f (double);

int main(){


}

double f(double x){

    return x < 4 ? 3
                 : 4 <= x and x < 7 ? x - 1
                                    : 7 <= x and x < 11 ? 6
                                                        : x - 5;
}