// A. Even Odds

#include <iostream>

using namespace std;


int main(){

    long long n, k;
    cin >> n >> k;

    long long num;
    // odds
    if (k <= n/2){
        num = 1 + (k-1)*2;
    }
    // corner case in the middle (because how "/" works with integers)
    else if(n%2!=0 && k==n/2+1){
        num = 1 + (k-1)*2;
    }
    // evens
    else {
        k = k-n/2;
        if (n%2==0){
            num = k*2;
        }
        else {
            num = (k-1)*2;
        }
    }

    cout << num << endl;

    return 0;
}