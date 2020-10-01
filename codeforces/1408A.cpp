// A. Circle Coloring

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        vector<vector<int>> v(3);
        int tmp;
        for (int i=0; i<3; ++i){
            for (int j=0; j<n; ++j){
                cin >> tmp;
                v[i].push_back(tmp);
            }
        }

        int first = v[0][0];
        int prev = v[0][0];
        cout << prev << ' ';
        for (int i=1; i<n; ++i){
            bool flag = false;
            for (int j=0; j<3; ++j){
                if (v[j][i] != prev && i!=n-1){
                    cout << v[j][i] << ' ';
                    prev = v[j][i];
                    break;
                }
                if (i==n-1){
                    for (int k=0; j<3; ++k){
                        if (v[k][i] != first && v[k][i] != prev){
                            cout << v[k][i] << ' ';
                            flag = true;
                            break;
                        }
                    }
                }
                if (flag) break;
            }
        }
        cout << endl;

    }

    return 0;
}