// A. Cubes Sorting

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(n);
        for (int i=0; i<n; ++i){
            cin >> v[i];
        }

        bool possible = false;
        for (int i=0; i<n-1; ++i){
            for (int j=i+1; j<n; ++j){
                if (v[i] <= v[j]){
                    possible = true;
                    break;
                }
            }
        }
        
        cout << (possible ? "YES" : "NO") << endl;
        /*
        // TLE
        // Count number of inversions
        int numOfInversions = 0;
        for (int i=0; i<n-1; ++i){
            for (int j=i+1; j<n; ++j){
                if (v[i] > v[j]){
                    numOfInversions++;
                }
            }
        }

        // long long maxOperations = ((long long)n*(n-1))/2 - 1;

        // cout << (numOfInversions > maxOperations ? "NO" : "YES") << endl;
        */


    }

    return 0;
}