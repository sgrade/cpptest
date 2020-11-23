// A. Fraction

#include <iostream>
#include <math.h>

using namespace std;


int main(){

    int n;
    cin >> n;

    int numerator, denominator;
    if (n % 2 == 0) numerator = n / 2 - 1;
    else numerator = floor(n / 2);

    denominator = n - numerator;

    bool found = false;
    while (!found){
        for (int i = 2; i < numerator + 1; ++i){
            if (numerator % i == 0 && denominator % i == 0){
                numerator -= 1;
                denominator +=1;
                break;
            }
            else {
                if (i == numerator){
                    found = true;
                }
            }
        }
        if (numerator == 1) found = true;
    }
    

    cout << numerator << ' ' << denominator << endl;

    return 0;
}
