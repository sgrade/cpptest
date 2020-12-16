// C. Unique Number

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int x;
        cin >> x;

        int ans = -1;
        
        // Editorial - https://codeforces.com/blog/entry/85594
        vector<int> v;
        int sum = 0;
        int i = 9;

        while (sum < x && i > 0){
            v.push_back(min(x - sum, i));
            sum += i;
            --i;
        }

        if (sum < x) cout << ans << endl;
        else {
            vector<int>::reverse_iterator rit = v.rbegin();
            for (; rit != v.rend(); rit++){
                cout << *rit;
            }
            cout << endl;
        }

    }

    return 0;
}
