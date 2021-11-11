// A. Second-Price Auction

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> p(n);
    for (auto &el: p) {
        cin >> el;
    }

    int winner, price = 0;

    winner = distance(begin(p), max_element(begin(p), end(p)));
    
    for (int i = 0; i < n; ++i) {
        if (p[i] != p[winner]) {
            if (p[i] > price) {
                price = p[i];
            }
        }
    }
    
    cout << winner + 1 << ' ' << price << endl;

    return 0;
}
