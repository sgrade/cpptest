// C. Ball in Berland
// TLE

#include <iostream>
#include <algorithm>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b, k;
        cin >> a >> b >> k;

        vector<int> boys(k), girls(k);
        for (auto &el: boys) cin >> el;
        for (auto &el: girls) cin >> el;

        int ans = 0;

        int boy, girl;
        // vector<int> chosen(k, -1);
        for (int i = 0; i < k-1; ++i){
            boy = boys[i];
            girl = girls[i];
            for (int j = i+1; j < k; ++j){
                if (boys[j] != boy && girls[j] != girl){
                    ++ans;
                }
            }
        }

        cout << ans << endl;

    }

    return 0;
}
