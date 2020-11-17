// A. Vasya and Chocolate

#include <iostream>

using namespace std;
using ull = unsigned long long;


int main(){

    ull t, s, a, b, c;
    cin >> t;

    while(t--){

        cin >> s >> a >> b >> c;
        ull buy = s / c;
        ull getForFree = (buy / a) * b;

        cout << buy + getForFree << endl;

    }

    return 0;
}
