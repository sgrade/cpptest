// C. Drazil and Factorial

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


vector<unsigned long long> allPrimeFactors(unsigned long long n)
{
    vector<unsigned long long> v;
    if (n == 0 || n == 1)
        return v;

    while (n % 2 == 0)
    {
        v.push_back(2);
        n /= 2;
    }

    for (unsigned long long i = 3; i <= sqrtl(n); i += 2)
    {
        while (n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }

    if (n > 2)
        v.push_back(n);

    return v;
}

int main(){

    unsigned long long n, x;
    cin >> n >> x;

    vector<unsigned long long> xx;
    while (x > 0) {
        xx.push_back(x % 10);
        x /= 10;
    }
    
    vector<unsigned long long> output, v, tmp;
    for (auto digit: xx) {
        tmp.clear();
        for (int i = digit; i > 1; --i)
        {
            v = allPrimeFactors(i);

            if (v.size() <= 1) 
            {
                output.push_back(i);
                break;
            }

            else 
            {
                tmp.insert(tmp.end(), v.begin(), v.end());
            }
        }
        // replace 3*2 with 3 (which is 3!)
        auto cnt = count(tmp.begin(), tmp.end(), 3);
        if (cnt > 0)
        {
            sort(tmp.begin(), tmp.end(), greater<unsigned long long>());
            cnt = min(cnt, count(tmp.begin(), tmp.end(), 2));
            tmp.erase(tmp.begin() + (tmp.size() - cnt), tmp.end());
        }
        output.insert(output.end(), tmp.begin(), tmp.end());
    }
    
    sort(output.begin(), output.end(), greater<unsigned long long>());
    for (auto el: output) cout << el;
    cout << endl;

    return 0;
}
