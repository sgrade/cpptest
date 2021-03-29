// A. GCD Sum

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
using ull = unsigned long long;


unsigned long long gcd(unsigned long long a, unsigned long long b) { 
	if (b == 0) {
		return a;
	} 
	return gcd(b, a % b);  
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        ull n;
        cin >> n;

        ull tmp, ans = n;
        ull x = 1;

        while (true) {
            ull sum_n = 0ULL;
            tmp = ans;
            while (tmp > 0) {
                sum_n += tmp % 10;
                tmp /= 10;
            }
            x = gcd(ans, sum_n);
            if (x > 1) {
                break;
            }
            ++ans;
        }

        cout << ans << endl;

    }

    return 0;
}
