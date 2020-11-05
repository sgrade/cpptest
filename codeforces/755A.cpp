// A. PolandBall and Hypothesis

#include <iostream>

using namespace std;


int isPrime(int x){
    if (x == 0 || x == 1) return false;
    else {
        for (int i = 2; i < x; ++i){
            if (x % i == 0) return false;
        }
    }
    return true;
}


int main(){

    int n;
    cin >> n;

    for (int i = 1; i < 1001; ++i){
        if (!isPrime(n * i + 1)){
            cout << i << endl;
            break;
        }
    }

    return 0;
}
