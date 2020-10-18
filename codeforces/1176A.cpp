// A. Divide it!

#include <iostream>

using namespace std;


int main(){
    
    int q;
    cin >> q;

    while (q--){

        unsigned long long n;
        cin >> n;

        bool stop = false;
        unsigned long long count = 0;
        while (n >= 1 && !stop){
            if (n%5 == 0) n = n/5 * 4;
            else if (n%3 == 0) n = n/3 * 2;
            else if (n%2 == 0) n = n/2;
            else {
                stop = true;
                break;
            }
            ++count;
        }

        if (n == 1) cout << count << endl;
        else cout << -1 << endl;

    }



    return 0;
}