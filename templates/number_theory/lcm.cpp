// Least Common Multiple
// https://en.cppreference.com/w/cpp/numeric/lcm
// In C++ STL since C++17
// By default with g++ it will not work, because it uses c++14:
// man g++ | grep "This is the default for C++ code"
// GNU dialect of -std=c++14.  This is the default for C++ code.

#include <iostream>
#include <numeric>

using namespace std;


int main(){

    unsigned long long a = 49;
    unsigned long long b = 10;

    cout << lcm(a, b) << endl;

    return 0;
}
