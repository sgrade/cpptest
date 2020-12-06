// A. Be Positive

#include <iostream>

int main(){

    int n;
    std::cin >> n;

    int a[n];
    for (auto &el: a) std::cin >> el;

    int pos = 0;
    int neg = 0;

    for (auto el: a){
        if (el > 0) ++pos;
        else if (el < 0) ++neg;
    }

    int target = (n + 2 - 1) / 2;
    if (pos >= target) puts("1");
    else if (neg >= target) puts("-1");
    else puts("0");

    return 0;
}
