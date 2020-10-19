// A. Sasha and Sticks

#include <iostream>

using namespace std;


int main(){

    unsigned long long n, k;
    cin >> n >> k;

    bool ans = false; 
    
    if (((n / k) % 2) == 1) {
        ans = true;
    }

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}