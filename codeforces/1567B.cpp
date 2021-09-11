// B. MEXor Mixup
#include <iostream>

using namespace std;


// Method to calculate xor
int computeXOR(int n) {
    // Source - https://www.geeksforgeeks.org/calculate-xor-1-n/

    // If n is a multiple of 4
    if (n % 4 == 0) {
        return n;
    }

    // If n%4 gives remainder 1
    if (n % 4 == 1) {
        return 1;
    }

    // If n%4 gives remainder 2
    if (n % 4 == 2) {
        return n + 1;
    }

    // If n%4 gives remainder 3
    return 0;
}
 

int main() {
    
    int t;
    cin >> t;

    while (t--) {

        int a, b;
        cin >> a >> b;

        int ans;

        // Editorial - https://codeforces.com/blog/entry/94581
        int x = computeXOR(a-1);

        if (x == b) {
            ans = a;
        }

        else {
            if ((x ^ b) != a) {
                ans = a + 1;
            }
            else {
                ans = a + 2;
            }
        }

        cout << ans << endl;
    }
}
