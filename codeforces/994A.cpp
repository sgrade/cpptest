// A. Fingerprints

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int x[n], y[m];
    for (auto &el: x) cin >> el;
    for (auto &el: y) cin >> el;

    map<int, int> ans;
    for (int i = 0; i<m; ++i){
        auto found = find(x, x+n, y[i]);
        if (found != x+n) {
            int index = distance(x, found);
            ans.insert(pair<int, int>(index, y[i]));
        }
    }

    for (auto el: ans){
        cout << el.second << ' ';
    }
    cout << endl;

    return 0;
}
