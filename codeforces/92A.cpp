// A. Chips

#include <iostream>

using namespace std;


int main(){

    int n, m;
    cin >> n >> m;

    int rnd = (1 + n) * n / 2;

    if (m > rnd) m %= rnd;

    for (int i = 1; i < n+1; ++i){
        if (m < i) break;
        else m -= i;
    }

    cout << m << endl;

    return 0;
}
