// C. Berland Regional
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
 
using namespace std;
using ull = unsigned long long;
 
int main() {
 
    int t;
    cin >> t;
 
    while (t--) {
 
        int n;
        cin >> n;
 
        vector<int> u(n);
        for (auto &el: u) {
            cin >> el;
        }
 
        map<int, vector<int>> universities;
        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            universities[u[i]].push_back(tmp);
        }
 
        vector<ull> ans(n);
        
        for (auto &university: universities) {
            sort(university.second.begin(), university.second.end());

            int max_k = university.second.size();

            vector<ull> sums(max_k+1);
            sums[0] = 0ULL;
            for (int k = 1; k < max_k+1; ++k) {
                sums[k] = sums[k-1] + university.second[k-1];
            }

            int rem;
            for (int k = 0; k < max_k; ++k) {
                // +1 is correction for 0-based indexing (k cannot be 0)
                rem = max_k % (k + 1);
                ans[k] += sums[max_k] - sums[rem];
            }
        }
 
        for (auto &el: ans) {
            cout << el << ' ';
        }
        cout << endl;
 
    }
 
    return 0;
}
