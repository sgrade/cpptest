// A. Copy-paste

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> v(n);
        for(int i=0; i<n; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int minV = v[0];
        
        int ans = 0;
        for (int i=1; i<n; ++i){
            ans += (k-v[i]) / minV;
        }

        cout << ans << endl;

    }

    return 0;
}
