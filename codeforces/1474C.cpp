// C. Array Destruction

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;


vector<int> check (int n, vector<int> v, int x){
    multiset<int> s(v.begin(), v.end());
    vector<int> output;
    for (int i = 0; i < n; ++i){
        auto last_element = s.end();
        --last_element;
        int y = x - *last_element;
        s.erase(last_element);
        auto y_it = s.find(y);
        if (y_it == s.end()) return {};
        output.push_back(x - y);
        output.push_back(y);
        x = max(x - y, y);
        s.erase(y_it);
    }
    return output;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(2 * n);
        for (auto &el: v) cin >> el;
        sort(v.begin(), v.end(), greater<int>());

        bool flag = false;
        
        // Editorial - https://codeforces.com/blog/entry/86933
        for (int i = 2 * n - 1; i > 0; --i){
            int x = v[0] + v[i];
            vector<int> ans = check(n, v, x);
            if (!ans.empty()){
                flag = true;
                cout << "YES\n" << x << endl;
                for (int j = 0; j < n; ++j){
                    cout << ans[2 * j] << " " << ans[2 * j + 1] << endl;
                }
                break;
            }
        }

        if (!flag) cout << "NO" << endl;

    }

    return 0;
}
