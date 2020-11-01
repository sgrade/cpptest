// B. Barrels

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        for (auto &el: a) cin >> el;
        sort(a.begin(), a.end(), greater<int>());

        long long ans = accumulate(a.begin(), a.begin()+k+1, 0ll);

        cout << ans << endl;

    }

    return 0;
}
