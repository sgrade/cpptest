// B. Flip the Bits
// NOT FINISHED

#include <iostream>
#include <string>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        
        string a, b;
        getline(cin >> ws, a);
        getline(cin >> ws, b);

        bool ans = true;

        if (n % 2 != 0 && a[n-1] != b[n-1]) {
            ans = false;
        }
        else {
            if (n % 2 != 0) {
                --n;
            }

            int zeroes_a = 0, zeroes_b = 0, ones_a = 0, ones_b = 0;
            int cnt = 0;
            for (int i = 0; i < n; i+=2) {

                
                cnt += 2;

                if (a[i] == '0')
                    ++zeroes_a;
                if (a[i+1] == '0')
                    ++zeroes_a;
                if (b[i] == '0')
                    ++zeroes_b;
                if (b[i+1] == '0')
                    ++zeroes_b;
                
                if (zeroes_a % 2 != zeroes_b % 2 || zeroes_a != zeroes_b) {
                    ans = false;
                    break;
                }
                
                ones_a = cnt - zeroes_a;
                ones_b = cnt - zeroes_b;

                if (zeroes_a == ones_a && zeroes_a == zeroes_b) {
                    zeroes_a = 0;
                    zeroes_b = 0;
                    cnt = 0;
                }
            }
        }
        
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}
