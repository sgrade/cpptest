// B. Yet Another Palindrome Problem

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        bool ans = false;
        
        vector<int> v(n);
        for (int i=0; i<n; ++i){
            cin >> v[i];
        }

        for (int i=2; i<n; ++i){
            if (find(v.begin(), v.begin()+(i-1), v[i]) != v.begin()+(i-1)){
                ans = true;
                break;
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}