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
        int odd=0, even=0;
        for(int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i]){
                if(i%2 == 0) ++even;
                else ++ odd;
            }
        }
        
        int diff = abs(odd-even);
        while (diff > 0 ){
            bool removeOdd = odd > even ? true : false;
            for(int i=0; i<n; ++i){
                if (removeOdd && i%2 != 0) {
                    if (v[i] == 1) {
                        v.erase(v.begin()+i);
                        break;
                    }
                }
                else if (!removeOdd && i%2 == 0){
                    if (v[i] == 1) {
                        v.erase(v.begin()+i);
                        break;
                    }
                }
            }
            --diff;
        }

        for(int i=0; i<n; ++i){
            cout << v[i] << ' ';
        }
        cout << endl;
    
    }

    return 0;
}