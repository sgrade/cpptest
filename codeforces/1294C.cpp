// C. Product of Three Numbers

#include <iostream>
#include <math.h>
#include <vector>
#include <set>

using namespace std;


vector<int> allPrimeFactors (int n){
    vector<int> v;
    if (n == 0 || n == 1) return v;

    while(n % 2 == 0){
        v.push_back(2);
        n /= 2;
    }

    for (int i=3; i <= sqrtl(n); i += 2){
        while (n % i == 0){
            v.push_back(i);
            n = n/i;
        }
    }
    
    if (n > 2) v.push_back(n);

    return v;

}


int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> factors = allPrimeFactors(n);

        bool ans = false;
        vector<int> output;

        int num_of_factors = factors.size();
        if (num_of_factors >= 3) {

            int first, second, third;

            first = factors[0];
            output.push_back(first);

            if (factors[1] != factors[0]) {
                second = factors[1];
            }
            else {
                second = factors[1] * factors[2];
            }
            output.push_back(second);

            third = n / (first * second);
            output.push_back(third);

            if (third != 1) {
                set<int> distinct_nums(begin(output), end(output));
                if (distinct_nums.size() == 3) {
                    ans = true;
                }
            }
        }

        if (ans) {
            cout << "YES" << endl;
            for (auto &el: output) {
                cout << el << ' ';
            }
            cout << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
