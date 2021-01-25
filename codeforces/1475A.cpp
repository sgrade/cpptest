// A. Odd Divisor

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        unsigned long long n;
        cin >> n;

        bool ans = false;
        if (n > 2){
            while (n != 2){
                if (n % 2 != 0) {
                    ans = true;
                    break;
                }
                n /= 2;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
