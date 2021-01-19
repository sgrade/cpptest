// 

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string a = "", b, d = "";
        getline(cin >> ws, b);

        if (b[0] == '0'){
            a += '1';
            d += '1';
        }
        else {
            a += '1';
            d += '2';
        }

        for (int i = 1; i < n; ++i){
            if (b[i] == '1') {
                if (d[i-1] == '2'){
                    a += '0';
                    d += '1';
                }
                // (b[i-1] == '1') 
                else {
                    a += '1';
                    d += '2';
                }
            }
            // == 0
            else {
                if (d[i-1] == '2') {
                    a += '1';
                    d += '1';
                }
                else if (d[i-1] == '1') {
                    a += '0';
                    d += '0';
                }
                else {
                    a += '1';
                    d += '1';
                }
            }
        }

        cout << a << endl;

    }

    return 0;
}
