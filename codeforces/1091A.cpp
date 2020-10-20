// A. New Year and the Christmas Ornament

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int y, b, r;
    cin >> y >> b >> r;

    // Editorial - https://codeforces.com/blog/entry/64196
    int mn = min({y+2, b+1, r});
    int sum = mn*3 - 3;

    cout << sum << endl;

    return 0;
}