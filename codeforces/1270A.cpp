// A. Card Game

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n, k1, k2;
        cin >> n >> k1 >> k2;

        int tmp;

        int max1 = 0;
        for (int i=0; i<k1; ++i){
            cin >> tmp;
            if (tmp > max1) max1 = tmp;
        }

        int max2 = 0;
        for (int i=0; i<k2; ++i){
            cin >> tmp;
            if (tmp > max2) max2 = tmp;
        }

        cout << (max1 > max2 ? "YES\n" : "NO\n");
    }

    return 0;
}
