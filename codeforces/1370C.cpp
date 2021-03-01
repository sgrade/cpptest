// C. Number Game

#include <iostream>
#include <math.h>
#include <vector>
#include <string>

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

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string ans = "Ashishgup";
        
        if (n == 1) ans = "FastestFinger";
        else if (n == 2) ans = "Ashishgup";
        else if (n % 2 == 0)
        {
            vector<unsigned long long> v = allPrimeFactors(n);
            int odd = 0, even = 0; 
            for (auto el: v)
            {
                if (el % 2 == 0)
                {
                    ++even;
                }
                else
                {
                    ++odd;
                }
            }

            // Editorial - https://codeforces.com/blog/entry/79107
            if (odd == 0)
            {
                ans = "FastestFinger";
            }
            else 
            {
                if (n % 4 != 0)
                {
                    if (isPrime(n / 2))
                        ans = "FastestFinger";
                }
            }
        }

        std::cout << ans << endl;
    }

    return 0;
}
