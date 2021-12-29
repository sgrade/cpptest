    // A. Robot Cleaner

    #include <iostream>

    using namespace std;


    int main() {

        int t;
        cin >> t;

        while (t--) {

            int n, m, rb, cb, rd, cd;
            cin >> n >> m >> rb >> cb >> rd >> cd;

            int ans = 0;

            int r = abs(rb - rd);
            int c = abs(cb - cd);
            
            // Editorial - https://codeforces.com/blog/entry/98463

            if (rb > rd) {
                r += (n - rb) * 2;
            }

            if (cb > cd) {
                c += (m - cb) * 2;
            }

            ans = min(r, c);

            cout << ans << endl;
        }

        return 0;
    }
