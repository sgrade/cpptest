// A. Okabe and Future Gadget Laboratory

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<vector<int>> a;

    for (int i = 0; i < n; ++i){
        vector<int> tmp(n);
        for (auto &el: tmp) cin >> el;
        a.push_back(tmp);
    }

    bool foundBad = false;

    for (int i = 0; i < n; ++i){
        if (foundBad) break;

        for (int j = 0; j < n; ++j){

            int target = a[i][j];

            if (foundBad) break;

            if (target != 1){
                vector<int> row(a[i].begin(), a[i].end());
                row.erase(row.begin() + j);

                vector<int> column;
                for (int k = 0; k < n; ++k){
                    if (k != i) column.push_back(a[k][j]);
                }

                bool foundTarget = false;
                for (auto x: row){
                    if (foundTarget) break;
                    for (auto y: column){
                        if (x + y == target){
                            foundTarget = true;
                            break;
                        }
                    }
                }
                if (!foundTarget) foundBad = true;
            }

        }
    }

    cout << (!foundBad ? "Yes" : "No") << endl;    

    return 0;
}
