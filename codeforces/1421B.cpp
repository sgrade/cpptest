// B. Putting Bricks in the Wall

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<string> v(n);
        for (int i=0; i<n; ++i){
            getline(cin >> ws, v[i]);
        }

        // top-right and bottom-left
        int str = v[0][1] - 48;
        int sbl = v[1][0] - 48;
        int fbl = v[n-1][n-2] - 48;
        int ftr = v[n-2][n-1] - 48;

        int c = 0;
        vector<vector<int>> ans;

        if (str==sbl || fbl==ftr){

            if (str==sbl){
                if (fbl == str){
                    ++c;
                    ans.push_back({n, n-1});
                }
                if (ftr == str){
                    ++c;
                    ans.push_back({n-1, n});
                }
            }
            else if (ftr==fbl){
                if (sbl == ftr){
                    ++c;
                    ans.push_back({2, 1});
                }
                if (str == ftr){
                    ++c;
                    ans.push_back({1, 2});
                }
            }
        }

        else {
            c += 2;
            // make stl = str = 1
            if (str == 0) ans.push_back({1, 2});
            else ans.push_back({2, 1});

            // make ftl = ftr = 0
            if (ftr == 1) ans.push_back({n-1, n});
            else ans.push_back({n, n-1});
        }
        

        cout << c << endl;
        if (c>0){

            for (auto it: ans){
                for (auto jit: it){
                    cout << jit << ' ';
                }
                cout << endl;
            }

        }
        
    }

    return 0;
}