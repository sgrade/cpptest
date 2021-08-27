// B. Scenes From a Memory

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>
#include <limits>

using namespace std;
using ull = unsigned long long;


bool isPrime (unsigned long long n){
    if (n == 0 || n == 1) return false;
    for (unsigned long long i=2; i <= sqrtl(n); ++i){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        int k;
        cin >> k;

        string s;
        getline (cin >> ws, s);

        vector<int> n(k);
        for (int i = 0; i < k; ++i) {
            n[i] = s[i] - 48;
        }

        int ans = 0;
        vector<int> output;

        // single digit
        for (auto &digit: n) {
            if (!isPrime(digit)) {
                ans = 1;
                output.push_back(digit);
                break;
            }
        }

        if (ans == 0) {
            // ends with two
            auto it_of_two = find(begin(n) + 1, end(n), 2);
            if (it_of_two != end(n)) {
                ans = 2;
                int idx_of_two = distance(begin(n), it_of_two);
                output.push_back(n[idx_of_two - 1]);
                output.push_back(2);
            }
        }

        if (ans == 0) {
            for (ull i = 12; i < numeric_limits<ull>::max(); ++i) {
                if (isPrime (i)) {
                    continue;
                }

                vector<int> tmp;
                ull tmp_i = i;
                while (tmp_i != 0) {
                    tmp.push_back(tmp_i % 10);
                    tmp_i /= 10;
                }
                reverse(begin(tmp), end(tmp));

                auto it = begin(n);
                bool found = true;
                for (int j = 0; j < tmp.size(); ++j) {
                    it = find(it, end(n), tmp[j]);
                    if (it == end(n)) {
                        found = false;
                        break;
                    }
                    ++it;
                }

                if (found) {
                    ans = tmp.size();
                    for (int k = 0; k < tmp.size(); ++k) {
                        output.push_back(tmp[k]);
                    }
                    break;
                }
            }
        }


        cout << ans << endl;
        for (auto &el: output) {
            cout << el;
        }
        cout << endl;

    }

    return 0;
}
