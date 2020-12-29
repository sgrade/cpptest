// A. Display Size

#include <iostream>
#include <math.h>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a = sqrt(n);

    while(a > 0){
        if(n % a == 0) break;
        else --a;
    }

    cout << a << ' ' << n / a << endl;

    return 0;
}
