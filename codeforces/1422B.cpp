// 

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);

        int tmp;
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                cin >> tmp;
                v[i].push_back(tmp);
            }
        }

        // Corners
        long long target = (0ull + v[0][0] + v[0][m-1] + v[n-1][0] + v[n-1][m-1]) / 4;
        long long minDistance=0ull;
        long long curDistance = abs(v[0][0] - target) + (abs(v[0][m-1] - target)) + (abs(v[n-1][m-1] - target) + abs(v[n-1][m-1] - target));
        long long prevDistance = curDistance;
        while (curDistance <= prevDistance){
            --target;
            curDistance = abs(v[0][0] - target) + (abs(v[0][m-1] - target)) + (abs(v[n-1][m-1] - target) + abs(v[n-1][m-1] - target));
        }
        
        cout << target << endl;
        
    }

    return 0;
}