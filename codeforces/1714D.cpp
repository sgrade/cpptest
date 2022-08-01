// D. Color with Occurrences
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> q;

    while (q--) {

        string t;
        cin >> t;

        int n;
        cin >> n;
        
        string tmp;
        vector<pair<string, int>> v;
        for (int i = 1; i < n + 1; ++i) {
            cin >> tmp;
            v.emplace_back(pair<string, int>(tmp, i));
        }
        sort(v.begin(), v.end(), [](pair<string, int> &p1, pair<string, int> &p2){
            return p1.first.size() > p2.first.size();
        });

        int ans = 0;

        cout << ans;
    }

    return 0;
}
