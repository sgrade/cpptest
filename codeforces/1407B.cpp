// B. Big Vova

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits>

using namespace std;


int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a % b);
}


int main(){

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) cin >> el;
  
        vector<int> output;
       
        int max_gcd = 0, cur_gcd;
        int max_index;
        
        while (!a.empty()) {

            // Idea from - https://codeforces.com/contest/1407/submission/92313307
            
            vector<pair<int, int>> v;
            
            for (int i = 0; i < a.size(); ++i) {
                cur_gcd = gcd(max_gcd, a[i]);
                v.emplace_back(make_pair(cur_gcd, i));
            }

            pair<int, int> m = *(max_element(v.begin(), v.end()));

            max_gcd = m.first;
            output.push_back(a[m.second]);
            a.erase(a.begin() + m.second);
        }

        for (auto el: output) cout << el << ' ';
        cout << endl;
    }

    return 0;
}
