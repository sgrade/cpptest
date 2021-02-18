// A. Odd Selection

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;
        
        vector<int> a(n);
        for (auto &el: a) cin >> el;

        int odd = count_if(a.begin(), a.end(), [](int x){
            return x % 2 != 0;
        });
        int even = n - odd;

        bool ans = false;

        int rem = max(0, x - even);
        if (rem % 2 != 0) {
            if (odd >= rem) ans = true;
        }
        else {
            if (even > 0 && odd >= rem + 1) ans = true;
        }

        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}
