// A. Display The Number

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        if (n >= 3 && n % 2 != 0){
            cout << '7';
            n -= 3;
        }
        for(int i = n; i > 0; i -= 2) cout << '1';
        cout << endl;
    }

    return 0;
}
