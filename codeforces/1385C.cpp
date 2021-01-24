// C. Make It Good

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &el: a) cin >> el;

        int ind = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] >= a[ind]) ind = i;
            else break;
        }

        for (int i = ind - 1; i >= 0; --i) {
            if (a[i] <= a[ind]) ind = i;
            else break;
        }

        cout << ind << endl;

    }

    return 0;
}
