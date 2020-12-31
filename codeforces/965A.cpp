// A. Paper Airplanes

#include <iostream>

using namespace std;


int main(){

    int k, n, s, p;
    cin >> k >> n >> s >> p;

    int sheets = (n + s - 1) / s;

    cout << (sheets * k + p - 1) / p << endl;

    return 0;
}
