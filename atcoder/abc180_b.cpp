// B - Various distances / 

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <math.h>
#include <limits>

using namespace std;


int main(){

    int n;
    cin >> n;

    unsigned long long man = 0;
    unsigned long long euc = 0;
    unsigned long long che = 0;

    long long tmp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        man += abs(tmp);
        euc += tmp * tmp;
        if (abs(tmp) > che) che = abs(tmp);
    }

    cout << man << endl;
    cout << setprecision(17) << sqrtl(euc) << endl;
    cout << che << endl;

    return 0;
}
