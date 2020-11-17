// C1. Binary Table (Easy Version)

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

map<int, vector<int>> convert(vector<int> b){

    // Returns mp[i] = v
    // where i is i-th conversion
    // v is the vector with indeces of the positions in b, which was changed on i-th conversion
    map<int, vector<int>> mp;
    vector<int> tmp(0, 0);
    mp[0] = tmp;

    // Number of conversions for one 2x2 square
    // pair.first:   number of ones in the square
    // pair.second:  required number of operations
    map<int, int> operationsMap = {
        {0, 0},
        {1, 3},
        {2, 2},
        {3, 1},
        {4, 4}
    };
    // Operations:
    // 0 0      0 1     1 0     0 0
    // 1 0  ->  0 1 ->  1 1 ->  0 0

    int ones = count(b.begin(), b.end(), 1);
    int conversions = operationsMap[ones];

    if (ones == 0) {
        return mp;
    }
    else {
        int onesToChange;
        int zerosToChange;

        for (int c = conversions; c > 0; --c){
            if (c == 3 || c == 2){
                onesToChange = 1;
                zerosToChange = 2;
            }
            else if (c == 1 || c == 4){
                onesToChange = 3;
                zerosToChange = 0;
            }

            vector<int> changedIndexes;
            for (int i = 0; i < 4; ++i){
                if (onesToChange == 0 && zerosToChange == 0) {
                    break;
                }
                int tmp = b[i];
                if (tmp == 1 && onesToChange > 0) {
                    b[i] = 0;
                    changedIndexes.push_back(i);
                    --onesToChange;
                }
                else if (tmp == 0 && zerosToChange > 0) {
                    b[i] = 1;
                    changedIndexes.push_back(i);
                    --zerosToChange;
                }
            }

            mp[c] = changedIndexes;
        }
    }

    return mp;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> v(n);
        vector<int> tmpV(m);
        string s;
        for (auto &el: v){ 
            getline(cin >> ws, s);
            for (int i = 0; i < m; ++i){
                tmpV[i] = (int)s[i] - 48;
            }
            el = tmpV;
        }

        int k = 0;
        vector<int> operations;
        
        for (int i = 0; i < n; i += 2){
            // if n is odd, we cannot process the last row (we need square 2x2)
            // so, we process the one befor last (once again) and the last one
            if (n % 2 != 0 && i == n - 1) --i;

            for (int j = 0; j < m; j += 2){
                if (m % 2 != 0 && j == m - 1) --j;

                vector<int> b(4);
                b[0] = v[i][j];
                b[1] = v[i][j+1];
                b[2] = v[i+1][j];
                b[3] = v[i+1][j+1];
                vector<pair<int, int>> bPositions(4);
                // Note: indexing in the output should start from 1
                bPositions[0] = pair<int, int>(i+1, j+1);
                bPositions[1] = pair<int, int>(i+1, j+1+1);
                bPositions[2] = pair<int, int>(i+1+1, j+1);
                bPositions[3] = pair<int, int>(i+1+1, j+1+1);

                map<int, vector<int>> mp = convert(b);
                if (mp.size() > 1){
                    k += mp.size() - 1;
                    for (auto &it: mp){
                        if (it.first == 0) continue;
                        else {
                            for (auto el: it.second){
                                operations.push_back(bPositions[el].first);
                                operations.push_back(bPositions[el].second);
                            }
                        }
                    }
                }

                v[i][j] = 0;
                v[i][j+1] = 0;
                v[i+1][j] = 0;
                v[i+1][j+1] = 0;
            }
        }

        // Convert rest (after even)


        cout << k << endl;
        int count = 0;
        for (int i = 0; i < operations.size(); i += 2){
            cout << operations[i] << ' ' << operations[i + 1] << ' ';
            ++count;
            if (count == 3) {
                cout << endl;
                count = 0;
            }
        }

    }

    return 0;
}
