// A. Eugeny and Array

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int tmp, positives = 0, negatives = 0;
    vector<int> v(n);
    for (auto &el: v) cin >> el;
    positives = count(v.begin(), v.end(), 1);
    negatives = count(v.begin(), v.end(), -1);
    int mn = min(negatives, positives);

    string output = "";
    int l, r;
    for (int i = 0; i < m; ++i) {
        cin >> l >> r;
        if ((r - l + 1) % 2 == 0 && (r - l + 1) / 2 <= mn) {
            output += "1\n";
        }
        else output += "0\n";
    }

    cout << output;

    return 0;
}
