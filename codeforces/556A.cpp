// A. Case of the Zeros and Ones

#include <iostream>
#include <string>

using namespace std;

int main(){

    int n;
    cin >> n;

    // Editorial - https://codeforces.com/blog/entry/18919
    string s;
    getline(cin >> ws, s);

    int numOfZeroes = 0;
    int numOfOnes = 0;
    for (int i=0; i<n; ++i){
        if (s[i] == '0') ++numOfZeroes;
        else ++numOfOnes;
    }

    cout << abs(numOfZeroes - numOfOnes) << endl;

    return 0;
}