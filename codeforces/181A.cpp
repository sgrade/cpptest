// A. Series of Crimes

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<int> y(n), x(m);

    string s;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        int idx = s.find('*');
        while (idx != string::npos) {
            ++y[i];
            ++x[idx];
            idx = s.find('*', idx+1);
        }
    }

    int tmp;
    
    tmp = distance(begin(y), find(begin(y), end(y), 1));
    cout << tmp + 1 << ' ';
    tmp = distance(begin(x), find(begin(x), end(x), 1));
    cout << tmp + 1 << endl;

    return 0;
}
