// A. Pens and Pencils

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;

        int pens = (a + c - 1) / c;
        int pencils = (b + d - 1) / d;
        if (pens + pencils > k){
            cout << -1 << endl;
        }
        else {
            cout << pens << ' ' << pencils << endl;
        }

    }

    return 0;
}