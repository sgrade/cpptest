// A. Cards

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    int n;
    scanf("%d\n", &n);

    string s;
    cin >> s;

    int numOfZero = count(s.begin(), s.end(), 'z');
    int numOfOne = (n - numOfZero*4) / 3;
    
    int i = 0;
    for (; i < numOfOne-1; ++i) printf()

    return 0;
}