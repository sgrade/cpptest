// C. Similar Pairs

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool ans = false;
        // Editorial - https://codeforces.com/blog/entry/77846
        
        vector<int> v(n);
        int numOfOdd = 0, numOfEven = 0;
        for (int i=0; i<n; ++i){
            cin >> v[i];
            if(v[i]%2 == 0) ++numOfEven;
            else ++numOfOdd;
        }

        if (numOfOdd%2 == numOfEven%2){
            if (numOfOdd%2==0 && numOfEven%2==0){
                ans = true;
            }
            else {
                sort(v.begin(), v.end());
                for (int i=1; i<n; ++i){
                    if (v[i]-v[i-1] == 1){
                        ans = true;
                        break;
                    }
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}