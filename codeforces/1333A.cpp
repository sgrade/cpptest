// A. Little Artem

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n, m;
        cin >> n >> m;

        vector<string> ans;
        for (int i = 0; i < n; ++i){
            string tmp(m, 'B');
            ans.push_back(tmp);
        }
        ans[0][0] = 'W';

        for(auto el: ans) cout << el << endl;
    }

    return 0;
}
