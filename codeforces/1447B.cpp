// B. Numbers Box

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<int> v(n * m);
        int tmp, negatives = 0;
        for (int i = 0; i < n * m; ++i){
            cin >> tmp;
            if (tmp < 0) ++negatives;
            v[i] = abs(tmp);
        }
        sort(v.begin(), v.end());

        // Editorial - https://codeforces.com/blog/entry/82067
        int ans = accumulate(v.begin(), v.end(), 0);
        if (v[0] != 0 && negatives % 2 != 0) ans -= 2 * v[0];      

        cout << ans << endl;

    }

    return 0;
}
