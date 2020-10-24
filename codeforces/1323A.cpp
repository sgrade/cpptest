// A. Even Subset Sum Problem

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &it: v) {
            cin >> it;
        }

        int ans = -1;
        vector<int> indices;

        // If at least one of the elements is even
        for (int i=0; i<n; ++i){
            if (v[i] % 2 == 0){
                ans = 1;
                indices.push_back(i+1);
                break;
            }
        }

        // If all the elements are odd
        if (ans == -1 && n > 1){
            ans = 2;
            indices.push_back(1);
            indices.push_back(2);
        }

        cout << ans << endl;
        if (ans > 0){
            for (auto el: indices){
                cout << el << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}