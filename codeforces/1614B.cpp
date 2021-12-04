// B. Divan and a New Project

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        
        int tmp;
        multimap<int, int> a;
        for (int i = 1; i <= n; ++i) {
            cin >> tmp;
            a.insert(pair<int, int>(tmp, i));
        }
        
        vector<int> output(n+1);
        auto rit = rbegin(a);

        int right = 1, left = -1;
        bool flag = true;
        long long T = 0;
        while (rit != rend(a)) {
            if (flag) {
                output[rit->second] = right;
                T += 2LL * rit->first * right;
                ++right;
            }
            else {
                output[rit->second] = left;
                T += 2LL * rit->first * abs(left);
                --left;
            }
            ++rit;
            flag = !flag;
        }

        cout << T << endl;
        for (auto &el: output) {
            cout << el << ' ';
        }
        cout << endl;
    }

    return 0;
}
