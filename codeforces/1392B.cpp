// B. Omkar and Infinity Clock

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        unsigned long long k;
        cin >> n >> k;

        vector<int> v(n);
        for (int i=0; i<n; ++i){
            cin >> v[i];
        }

        unsigned long long operations = 1;
        if (k>1) {
            operations = k%2 != 0 ? 3 : 2;
        }
        while (operations--){   
            int vMax = *max_element(v.begin(), v.end()) ;
            for (int i = 0; i<n; ++i){
                v[i] = vMax - v[i];
            }
        }

        for (auto it: v){
            cout << it << ' ';
        }
        cout << endl;

    }

    return 0;
}