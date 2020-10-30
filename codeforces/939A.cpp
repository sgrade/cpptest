// A. Love Triangle

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    int tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        v[i] = tmp-1;
    }

    // first, second, third
    pair<int, int> f, s, t;

    bool ans = false;
    for (int i=0; i<n; ++i){
        f = pair<int, int>(i, v[i]);
        s = pair<int, int>(f.second, v[f.second]);
        t = pair<int, int>(s.second, v[s.second]);
        if (t.second == f.first) {
            ans = true;
            break;
        }
    }

    cout << (ans ? "YES\n" : "NO\n");

    return 0;
}
