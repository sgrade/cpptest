// B. Kalindrome Array

#include <iostream>
#include <vector>
#include <set>

using namespace std;


bool is_palindrome(int l, int r, int &x, vector<int> &a) {
    while (l <= r) {
        if (a[l] != a[r]) {
            if (a[l] == x) {
                ++l;
                continue;
            }
            else if (a[r] == x) {
                --r;
                continue;
            }
            else {
                return false;
            }
        }
        ++l;
        --r;
    }
    return true;
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

        bool ans = false;

        set<int> checked;
        int l = 0, r = n-1;
        while (l <= r) {
            if (a[l] != a[r]) {
                vector<int> xx = {a[l], a[r]};
                for (auto &x: xx) {
                    if (checked.find(x) == end(checked)) {
                        checked.insert(x);
                        ans = is_palindrome(l, r, x, a);
                        if (ans) {
                            goto ANS;
                        }
                    }
                }
                if (!ans) {
                    break;
                }
            }
            ++l;
            --r;
        }
        if (l >=r ) {
            ans = true;
        }

        ANS:
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
