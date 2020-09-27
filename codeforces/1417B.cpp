// B. Two Arrays

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, T;
        cin >> n >> T;

        int ans[n];

        // Editorial - https://codeforces.com/blog/entry/83036
        vector<int> x, y, z;
        int tmp;
        int flag = 0;
        for(int i=0; i<n; ++i){
            cin >> tmp;
            if (T%2==0 and tmp == T/2) {
                ans[i] = (flag++)%2;
            }
            else if (tmp*2 < T) ans[i] = 0;
            else ans[i] = 1;
        }

        for (auto it: ans){
            cout << it << ' ';
        }
        cout << endl;

    }

    return 0;
}
