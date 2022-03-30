// A. Good Pairs

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        
        int n;
        cin >> n;

        vector<int> a(n);
        for (int &el: a) {
            cin >> el;
        }

        // Editorial - https://codeforces.com/blog/entry/101211
        
        auto p = minmax_element(begin(a), end(a));

        int i = distance(begin(a), p.first) + 1;
        int j = distance(begin(a), p.second) + 1;

        cout << i << ' ' << j << '\n';
    }

    return 0;
}
