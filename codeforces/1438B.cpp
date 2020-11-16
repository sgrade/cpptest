// B. Valerii Against Everyone

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <numeric>

using namespace std;
using ull = unsigned long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool ans = false;

        vector<ull> b;
        ull tmp;

        // Editorial - https://codeforces.com/blog/entry/84589
        for (int i = 0; i<n; ++i){
            cin >> tmp;
            if (!ans){
                auto found = find(b.begin(), b.end(), tmp);
                // two equal subarrays of one element each
                if (found != b.end()){
                    ans = true;
                }
                else {
                    b.push_back(tmp);
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
