// A. Lunar New Year and Cross Counting

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<string> m(n);
    for (auto &el: m) getline(cin >> ws, el);

    int ans = 0;
    for (int i = 1; i < n-1; ++i){
        for (int j = 1; j < n-1; ++j){
            if (m[i][j] == '.') continue;
            else{
                if (m[i-1][j-1] == 'X' && m[i-1][j+1] == 'X' && m[i+1][j-1] == 'X' && m[i+1][j+1] == 'X') ++ans;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
