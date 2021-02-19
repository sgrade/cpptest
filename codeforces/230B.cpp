// B. T-primes

#include <iostream>
#include <math.h>
#include <map>

using namespace std;


bool isPrime(unsigned long long n)
{
    if (n == 0 || n == 1)
        return false;
    for (unsigned long long i = 2; i <= sqrtl(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}


int main(){

    int n;
    cin >> n;

    map<unsigned long long, bool> mp;
    bool ans;

    unsigned long long x, tmp;
    while (n--) {

        cin >> x;

        if (mp.find(x) == mp.end()){
            // The idea is from the editorial - https://codeforces.com/blog/entry/5437
            tmp = sqrt(x);
            ans = tmp * tmp == x && isPrime(tmp);
            mp.insert(pair<unsigned long long, bool>(x, ans));
        }

        cout << (mp[x] ? "YES" : "NO") << endl;
    }

    return 0;
}
