// A. Pasha and Hamsters

#include <iostream>
#include <vector>

using namespace std;


int main() {

    int n, a, b;
    cin >> n >> a >> b;

    vector<int> ans(n);
    
    int tmp;
    for (int i = 0; i < a; ++i) {
        cin >> tmp;
        --tmp;
        ans[tmp] = 1;
    }
    for (int i = 0; i < b; ++i) {
        cin >> tmp;
        --tmp;
        ans[tmp] = 2;
    }

    for (auto &el: ans) {
        cout << el << ' ';
    }
    cout << endl;

    return 0;
}
