// A. Array Rearrangment

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        vector<int> b(n);
        for (auto &el: a) cin >> el;
        sort(a.begin(), a.end());
        for (auto &el: b) cin >> el;
        sort(b.begin(), b.end(), greater<int>());

        bool ans = true;
        for (int i=0; i<n; ++i){
            if(a[i]+b[i] > x){
                ans = false;
                break;
            }
        }

        cout << (ans ? "Yes\n" : "No\n");

    }

    return 0;
}
