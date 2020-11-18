// A. Reconnaissance 2

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a){
        cin >> el;
    }

    int diff = abs(a[n-1] - a[0]);
    int indexes[2] = {0, n-1};

    if (n > 2){
        for (int i = 1; i < n; ++i){
            if (abs(a[i] - a[i-1]) < diff){
                diff = abs(a[i] - a[i-1]);
                indexes[0] = i - 1;
                indexes[1] = i;
            }
        }
    }

    cout << indexes[0] + 1 << ' ' << indexes[1] + 1 << endl;

    return 0;
}
