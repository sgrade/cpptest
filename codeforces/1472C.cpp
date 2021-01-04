// C. Long Jumps
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ull = unsigned long long;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<ull> v(n+1);
        v[0] = 0;
        for (int i = 1; i < n+1; ++i) cin >> v[i];

        ull maxScore = 0;

        for (ull j = 1; j < n+1; ++j){
            ull i = j;
            while (i <= n){
                i += v[i];
            }
            if (i - j > maxScore) maxScore = i - j;
        }

        cout << maxScore << endl;

    }

    return 0;
}
