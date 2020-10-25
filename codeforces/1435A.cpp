// A. Finding Sasuke

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &it: v) cin >> it;

        vector<int> ans(n, 1);
        
        int sum = accumulate(v.begin(), v.end(), 0);

        if (sum != 0){

            vector<int> tmp(n);
            for (auto el: v) tmp.push_back(el);

            reverse(tmp.begin(), tmp.end());

            for (int i=0; i<n/2; ++i){
                tmp[i] *= -1;
            }

            for (int i=0; i<n; ++i){
                ans[i] = tmp[i];
            }

        }

        for (auto el: ans) {
            cout << el << ' ';
        }
        cout << endl;

    }

    return 0;
}
