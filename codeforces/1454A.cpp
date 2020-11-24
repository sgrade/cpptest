// 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v;
        v.push_back(n);
        for (int i = 1; i < n; i++){
            v.push_back(i);
        }
        
        for (auto el: v) cout << el << ' ';
        cout << endl;

    }

    return 0;
}
