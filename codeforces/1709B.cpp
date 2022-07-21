// B. Also Try Minecraft

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<long long> a(n);
    for (long long &el: a) cin >> el;

    vector<long long> left_to_right (n + 1, 0LL);
    for (int i = 2; i < n + 1; ++i) {
        if (a[i - 2] <= a[i - 1]) {
            left_to_right[i] = left_to_right[i - 1];
        }
        else {
            left_to_right[i] = left_to_right[i - 1] + (a[i - 2] - a[i - 1]);
        }
    }
    vector<long long> right_to_left (n + 1, 0LL);
    for (int i = n - 2; i > - 1; --i) {
        if (a[i] >= a[i + 1]) {
            right_to_left[i + 1] = right_to_left[i + 2];
        }
        else {
            right_to_left[i + 1] = right_to_left[i + 2] + (a[i + 1] - a[i]);
        }
    }

    int s, t;
    long long fall;
    for (int j = 0; j < m; ++j) {
        cin >> s >> t;
        if (s == t) 
            fall = 0;
        else if (s < t) {
            fall = left_to_right[t] - left_to_right[s];
        }
        else {
            fall = right_to_left[t] - right_to_left[s];
        }
        cout << fall << '\n';
    }

    return 0;
}
