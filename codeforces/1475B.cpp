// B. New Year's Number

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool ans = false;

        if (n >= 2020){
            int t = n / 2020;
            if (n % 2020 == 0 || n % 2020 <= t) ans = true;
        }
        
        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
