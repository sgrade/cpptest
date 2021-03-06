// A. Lineland Mail

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    long long n;
    cin >> n;

    long long x[n];
    for (auto &el: x) cin >> el;
   
    cout << x[1] - x[0] << ' ' << x[n-1] - x[0] << endl;
    
    for(int i = 1; i < n-1; ++i){
        cout << min(x[i] - x[i-1], x[i+1] - x[i]) << ' ';
        cout << max(x[i] - x[0], x[n-1] - x[i]) << endl;
    }

    cout << x[n-1] - x[n-2] << ' ' << x[n-1] - x[0] << endl;

    return 0;
}
