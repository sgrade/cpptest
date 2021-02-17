// B. BerSU Ball

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n, m;
    cin >> n;
    vector<int> a(n);
    for (auto &el: a) cin >> el;
    cin >> m;
    vector<int> b(m);
    for (auto &el: b) cin >> el;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int pairs = 0;
    vector<bool> b_paired(m, false);
    
    for (int i = 0; i < n; ++i) {
        size_t index = 0;
        vector<int>::iterator it = b.begin();
        while (index < m) {
            it = find_if(b.begin() + index, b.end(), [a, i](int x) {
                return abs(x - a[i]) < 2;
            });
            if (it != b.end())
            {
                index = distance(b.begin(), it);
                if (!b_paired[index]) 
                {
                    ++pairs;
                    b_paired[index] = true;
                    break;
                }
                ++index;
            }
            else break;
        }
    }

    cout << pairs << endl;

    return 0;
}
