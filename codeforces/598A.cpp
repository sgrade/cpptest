// A. Tricky Sum

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main() {

    vector<long long> powers = {1};
    long long p = 1;
    while (p <= 1000000000) {
        p *= 2;
        powers.push_back(p);
    }
    
    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        long long sum = -1;

        if (n > 1) {
            sum = (1 + n) * n / 2;

            long long tmp = 0;
            int i = 0;
            while (powers[i] <= n) {
                sum -= 2 * powers[i];
                ++i;
            }
        }
        
        cout << sum << endl;
    }

    return 0;
}
