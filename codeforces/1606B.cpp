// B. Update Files
// Wrong answer on test 3

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
using ll = long long;

// Source of the below function - 
// https://www.geeksforgeeks.org/highest-power-2-less-equal-given-number/
ll nextPowerOf2(ll n)
{
    ll count = 0;
     
    // First n in the below condition
    // is for the case where n is 0
    if (n && !(n & (n - 1)))
        return n;
     
    while( n != 0)
    {
        n >>= 1;
        count += 1;
    }
     
    return 1 << count;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        ll n, k;
        cin >> n >> k;

        ll ans;
        
        // We can scale *2 every hour up to p
        ll p = nextPowerOf2(k);

        if (p >= n) {
            ans = (ll)log2(n);
            // Check if n is not a power of two
            // https://www.geeksforgeeks.org/program-to-find-whether-a-given-number-is-power-of-2/
            if (n & (n - 1)) {
                ++ans;
            }
        }
        
        else {
            ans = (ll)log2(p);
            ans += ((n - p) + k - 1) / k;
        }
        
        cout << ans << endl;
    }

    return 0;
}
