// B. A New Technique

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<vector<int>> rows(n);
        vector<vector<int>> columns(m);

        vector<int> tmpR(m);
        int tmp;
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                cin >> tmpR[j];
            }
            rows[i] = tmpR;
        }

        vector<int> tmpC(n);
        for (int j=0; j<m; ++j){
            for (int i=0; i<n; ++i){
                cin >> tmpC[i];
            }
            columns[j] = tmpC;
        }

        vector<vector<int>> ans;

        int targetColumn = -1;
        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                if (rows[i][j] == columns[0][0]){
                    targetColumn = j;
                    break;
                }
            }
            if (targetColumn != -1){
                break;
            }
        }

        for (int k = 0; k<n; ++k){
            for (int i=0; i<n; ++i){
                if (rows[i][targetColumn] == columns[0][k]){
                    ans.push_back(rows[i]);
                    break;
                }
            }
        }

        for (int i=0; i<n; ++i){
            for (int j=0; j<m; ++j){
                cout << ans[i][j] << ' ';
            }
            cout << endl;
        }

    }

    return 0;
}
