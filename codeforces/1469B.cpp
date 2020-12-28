// B. Red and Blue

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        vector<int> r(n);
        for (auto &el: r) cin >> el;

        int m;
        cin >> m;
        vector<int> b(m);
        for (auto &el: b) cin >> el;
       
        int rMax = 0;
        int rSum = 0;
        for (int i = 0; i < n; ++i){
            rSum += r[i];
            rMax = max(rMax, rSum);
        }

        int bMax = 0;
        int bSum = 0;
        for (int i = 0; i < m; ++i){
            bSum += b[i];
            bMax = max(bMax, bSum);
        }

        cout << rMax + bMax << endl;

    }

    return 0;
}
