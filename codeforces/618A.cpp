// A. Slime Combining

#include <iostream>
#include <vector>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> ans;
    for (int i = 0; i < n; ++i){
        ans.push_back(1);
        while (ans.size() > 1 && ans[ans.size()-2] == ans[ans.size()-1]){
            ++ans[ans.size()-2];
            ans.pop_back();
        }
    }

    for (auto el: ans){
        cout << el << ' ';
    }
    cout << endl;

    return 0;
}
