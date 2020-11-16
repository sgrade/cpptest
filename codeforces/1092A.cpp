// A. Uniform String

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, k;
        cin >> n >> k;

        while(n > 0){
            int limit = min(k, n);
            for (int i = 0; i < limit; ++i){
                cout << (char)(i + 97);
                --n;
            }
        }
        cout << endl;

    }

    return 0;
}
