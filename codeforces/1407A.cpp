// A. Ahahahahahahahaha

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        
        // Editorial - https://codeforces.com/blog/entry/82417
        int zeros = 0, ones = 0;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i]) ++ones;
            else ++ zeros;
        }
        
        if (zeros >= n/2){
            // we remove all ones
            cout << zeros << endl;
            for (int i=0; i<zeros; ++i) {
                cout << 0 << ' ';
            }
        }
        else {
            // we remove all zeros
            cout << ones - ones%2 << endl;
            for (int i=0; i<ones-ones%2; ++i){
                cout << 1 << ' ';
            }
        }

        cout << endl;
    
    }

    return 0;
}