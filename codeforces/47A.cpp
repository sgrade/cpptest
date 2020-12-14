// A. Triangular numbers

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    int s=0, i=1;
    while (s < n){
        s += i;
        ++i;
    }

    cout << (s == n ? "YES" : "NO") << endl;

    return 0;
}
