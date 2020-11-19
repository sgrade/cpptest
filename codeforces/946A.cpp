// A. Partition

#include <iostream>
#include <numeric>

using namespace std;


int main(){

    int n;
    cin >> n;

    int a[n];
    for (auto &el: a){
        cin >> el;
        if (el < 0) el *= -1;
    }

    cout << accumulate(a, a+n, 0) << endl;

    return 0;
}
