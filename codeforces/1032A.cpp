// A. Kitchen Utensils

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &el: a) {
        cin >> el;
    }
    sort (begin(a), end(a));

    set<int> st(begin(a), end(a));
    int t = size(st);
    
    int mx = *rbegin(st);
    int p = (mx + k - 1) / k;

    int ans = p * t * k - n;

    cout << ans << endl;
    
    return 0;
}
