// A - 106
// UNSOLVED - 1 test case

#include <iostream>
#include <math.h>

using namespace std;


int main(){

    unsigned long long n;
    cin >> n;

    unsigned long long a=0, b=0;

    bool found = false;
    
    if (n == 2){
        found = true;
    }
    else if (n == 4){
        found = true;
        a = 1;
        b = 0;
    }
    else if (n == 6){
        found = true;
        a = 0;
        b = 1;
    }
    else if (n > 6){
        for (unsigned long long apow=3; apow<=(n-5); apow *= 3){
            ++a;
            b = 0;
            for (unsigned long long bpow=5; bpow<=(n-3); bpow *= 5){
                ++b;
                unsigned long long sum = apow + bpow;
                if (sum == n){
                    found = true;
                    break;
                }
            }
            if (found){
                break;
            }
        }
    }

    if (!found) {
        cout << -1 << endl;
    }
    else {
        cout << a << ' ' << b << endl;
    }

    return 0;
}
