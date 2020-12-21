// A. Save Luke

#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    float d, l, v1, v2;
    cin >> d >> l >> v1 >> v2;

    cout << fixed << setprecision(6) << (l - d) / (v1 + v2) << endl;

    return 0;
}
