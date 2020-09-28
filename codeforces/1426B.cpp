// B. Symmetric Matrix

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        // n - num of types
        // m - size of square
        int n, m;
        cin >> n >> m;

        bool output = false;

        for (int i=0; i<n; ++i){
            int tl, tr, bl, br;
            cin >> tl >> tr;
            cin >> bl >> br;

            /*
            if (tl==br && tr==bl){
                output = true;
                break;
            }
            */
            
            if (tr==bl){
                output = true;
            }
        }

        if (m%2 != 0){
            output = false;
        }

        cout << (output ? "YES" : "NO") << endl;

    }

    return 0;
}