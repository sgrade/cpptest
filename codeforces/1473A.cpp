// A. Replacing Elements

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, d;
        cin >> n >> d;

        int a[n];
        for(auto &el: a) cin >> el;
        sort(a, a+n);

        if (a[n-1] <= d || a[0] + a[1] <= d){
            cout << "YES";
        }
        else cout << "NO";

        cout << endl;

    }

    return 0;
}
