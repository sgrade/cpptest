// B. Middle Class

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
        long long x;
        cin >> n >> x;

        vector<int> v(n);
        for (int i=0; i<n; ++i){
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int ans = 0;
        int averageWealth = 0;
        long long acc = accumulate(v.begin(), v.end(), 0ull);
        for (int i=0; i<n; ++i){
            // Note 0 is casted as ull
            // Otherwise accumulate overflows
            averageWealth = acc / (n-i);
            if (averageWealth >= x){
                ans = n-i;
                break;
            }
            acc -= v[i];
        }

        cout << ans << endl;

    }
    
    return 0;
}