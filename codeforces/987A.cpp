// A. Infinity Gauntlet

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    map<string, string> colors = {
        {"purple", "Power"},
        {"green", "Time"},
        {"blue", "Space"},
        {"orange", "Soul"},
        {"red", "Reality"},
        {"yellow", "Mind"}
    };

    int n;
    cin >> n;

    vector<string> present;
    string s;
    for (int i = 0; i < n; ++i){
        getline(cin >> ws, s);
        present.push_back(s);
    }

    vector<string> ans;
    for (auto el: colors){
        auto found = find(present.begin(), present.end(), el.first);
        if (found == present.end()) ans.push_back(el.second);
    }

    cout << ans.size() << endl;
    for (auto el: ans){
        cout << el << endl;
    }

    return 0;
}
