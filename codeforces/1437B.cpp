// B. Reverse Binary Strings

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        string s;
        getline(cin >> ws, s);

        int onesToSwap=0, prev, cur;
        for (int i=1; i<n; ++i){
            prev = (int)s[i-1] - 48;
            cur = (int)s[i] - 48;
            if (prev == 1 && cur == 1) ++onesToSwap;
        }

        int zerosToSwap=0;
        for (int i=1; i<n; ++i){
            prev = (int)s[i-1] - 48;
            cur = (int)s[i] - 48;
            if (prev == 0 && cur == 0) ++zerosToSwap;
        }

        cout << max(onesToSwap, zerosToSwap) << endl;
        
    }

    return 0;
}
