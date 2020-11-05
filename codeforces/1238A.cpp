// A. Prime Subtraction

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        unsigned long long x, y;
        cin >> x >> y;

        // Editorial - https://codeforces.com/blog/entry/70450
        cout << (x - y == 1 ? "NO" : "YES") << endl;

    }

    return 0;
}
