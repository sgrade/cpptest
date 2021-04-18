// E. Four Segments

#include <iostream>
#include <algorithm>>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {
        int a[4];
        for (auto &el: a) {
            cin >> el;
        }
        sort(a, a+4);
        cout << a[0] * a[2] << endl;
    }

    return 0;
}
