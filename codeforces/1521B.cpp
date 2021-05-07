// B. Nastia and a Good Array
// WRONG ANSWER

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


unsigned long long gcd(unsigned long long a, unsigned long long b) { 
	if (b == 0) {
		return a;
	} 
	return gcd(b, a % b);  
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &el: a) {
            cin >> el;
        }

        int k = 0;

        vector<vector<int>> ans;

        if (n > 1) {
            int x = 11;
            vector<int> tmp_v;
            int i = 1;
            vector<int> v(n);
            for (; i < n; ++i) {

                ++k;
                tmp_v.clear();

                // Indexes in the answer should be 1-based (not 0-based)
                tmp_v.push_back(i);
                tmp_v.push_back(i+1);

                tmp_v.push_back(x);
                tmp_v.push_back(min(a[i-1], a[i]));

                ans.push_back(tmp_v);

                v[i-1] = tmp_v[2];
                v[i] = tmp_v[3];

                if (x == 13) {
                    x = 11;
                }
                else {
                    x = 13;
                }
            }

            if (tmp_v[2] == tmp_v[3]) {
                int y;
                if (tmp_v[2]  == 11) {
                    y = 111;
                }
                else {
                    y = 113;
                }

                ++k;
                tmp_v.clear();

                tmp_v.push_back(i);
                tmp_v.push_back(i+1);

                tmp_v.push_back(x);
                tmp_v.push_back(y);

                ans.push_back(tmp_v);

                v[i-2] = tmp_v[2];
                v[i-1] = tmp_v[3];
            }
        }

        cout << k << endl;
        for (auto &vect: ans) {
            for (auto &el: vect) {
                cout << el << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
