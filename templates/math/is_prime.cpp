#include <bits/stdc++.h>

using namespace std;


bool isPrime (int num) {
    if (num < 2)
        return false;
    if (num == 2 || num == 3)
        return true;
    if (num % 2 == 0)
        return false;
    for (int divisor = 3; divisor * divisor <= num; divisor += 2) {
        if (num % divisor == 0)
            return false;
    }
    return true;
}
