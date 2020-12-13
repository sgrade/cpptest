// A. Blackjack

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    // https://codeforces.com/contest/104/submission/15913615
    n -= 10;
    cout << (1 <= n && n <= 11) * 4 + (n == 10) * 11 << endl;

    return 0;
}
