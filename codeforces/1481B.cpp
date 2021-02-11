// B. New Colony

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        int h[n];
        for (auto &el: h) cin >> el;

        int pos = -1;
        while (k > 0) {
            int i = 0;
            for (; i < n-1; ++i) {
                if (h[i] < h[i+1]) {
                    ++h[i];
                    --k;
                    pos = i + 1;
                    break;
                }
                else {
                    pos = -1;
                }
            }
            if (pos == - 1) break;
        }

        cout << pos << endl;
    }

    return 0;
}
