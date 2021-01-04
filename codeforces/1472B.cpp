// B. Fair Division

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        int a[n];
        int tmp, ones = 0, twos = 0;
        for (int i = 0; i < n; ++i){
            cin >> tmp;
            if (tmp == 1) ++ones;
            else ++twos;
        }

        bool ans = false;
        if (twos % 2 == 0){
            if (ones % 2 == 0) ans = true;
        }
        else {
            if (ones >= 2 && (ones - 2) % 2 == 0) ans = true;
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
