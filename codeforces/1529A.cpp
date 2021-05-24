// A. Eshag Loves Big Arrays

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int tmp;
        multiset<int> a;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            a.insert(tmp);
        }

        int first_count = a.count(*a.begin());

        cout << n - first_count << endl;        

    }

    return 0;
}
