// A. Marketing Scheme
// NOT FINISHED

#include <iostream>


using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int l, r;
        cin >> l >> r;

        bool ans = false;

        // ceil: (a + b - 1) / b
        int start = (r + 2 - 1) / 2;
        
        float tmp = ((float)start) / 2;
        int tmp1 = l%start;
        for(int i = start; i < )
        if (((float)start) / 2 >= l%start){
            ans = true;
        }

        cout << (ans ? "YES\n" : "NO\n");

    }

    return 0;
}
