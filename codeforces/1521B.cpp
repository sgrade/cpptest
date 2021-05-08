// B. Nastia and a Good Array
// Wrong answer on test 2

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

                a[i-1] = tmp_v[2];
                a[i] = tmp_v[3];

                if (x == 13) {
                    x = 11;
                }
                else {
                    x = 13;
                }
            }

            if (tmp_v[2] == tmp_v[3]) {
                x = tmp_v[2];
                
                tmp_v.clear();
                tmp_v.push_back(i);
                tmp_v.push_back(i+1);

                tmp_v.push_back(x);
                if (x == 11) {
                    tmp_v.push_back(113);
                }
                else {
                    tmp_v.push_back(111);
                }

                ans.push_back(tmp_v);
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
