// A. Year of University Entrance

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &el: a) {
        cin >> el;
    }

    sort(begin(a), end(a));

    cout << a[n/2] << endl;

    return 0;
}
