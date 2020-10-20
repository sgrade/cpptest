// B. Yet Another Bookshelf

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
        int zeros = 0;
        int tmpZeros = 0;
        bool count = false;
        for (int i=0; i<n; ++i){
            cin >> v[i];
            if (v[i] == 1){
                count = true;
                zeros += tmpZeros;
                tmpZeros = 0;
            } 
            if (count && v[i]==0){
                ++tmpZeros;
            }
        }

        cout << zeros << endl;

    }

    return 0;
}