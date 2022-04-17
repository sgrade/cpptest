// A. Red Versus Blue

#include <iostream>
#include <vector>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n, r, b;
        cin >> n >> r >> b;

        int rr = r / (b + 1);
        int rem = r - rr * b;
        int last = min(rem, rr);
        rem -= last;

        vector<char> output;
        int bb = b;
        while (bb--) {
            for (int i = 0; i < rr; ++i) {
                output.push_back('R');
            }
            if (rem > 0) {
                output.push_back('R');
                --rem;
            }
            output.push_back('B');
        }

        while(last--) {
            output.push_back('R');
        }

        for (char &ch: output) {
            cout << ch;
        }
        cout << '\n';
    }

    return 0;
}
