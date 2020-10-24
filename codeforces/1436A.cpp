// A. Reorder

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for (auto &it: v) cin >> it;

        int sum = accumulate(v.begin(), v.end(), 0);
        
        cout << (sum == m ? "YES\n" : "NO\n");

    }

    return 0;
}
