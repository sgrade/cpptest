// A. Distance and Axis

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, k;
        cin >> n >> k;

        int output = 0;

        // Editorial - https://codeforces.com/blog/entry/81700
        if (n<k) output = k - n;
        else if (n%2 != k%2) output = 1;

        cout << output << endl;

    }

    return 0;
}