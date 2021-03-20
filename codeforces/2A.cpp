// A. Winner

#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


int main() {

    int n;
    cin >> n;

    map<string, int> scores;
    vector<pair<int, string>> chrono;

    string name;
    int score;
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        scores[name] += score;
        chrono.push_back(pair(scores[name], name));
    }

    int mx = -1000;
    for (auto el: scores) {
        mx = max(mx, el.second);
    }
    
    vector<string> candidate_winners;
    for (auto el: scores) {
        if (el.second == mx) {
            candidate_winners.push_back(el.first);
        }
    }
  
    auto it = find_if(chrono.begin(), chrono.end(), [candidate_winners, mx](pair<int, string> x){
        return find(candidate_winners.begin(), candidate_winners.end(), x.second) != candidate_winners.end() && x.first >= mx;
    });
    cout << it->second << endl;
    
    return 0;
}
