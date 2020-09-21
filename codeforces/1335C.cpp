// C. Two Teams Composing

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        // <skill, number of occurances>
        unordered_map<int, int> mp;
        int tmp;
        for (int i=0; i<n; ++i){
            cin >> tmp;
            ++mp[tmp];
        }

        // <number of occurances, skill>
        multimap<int, int> sortedMp;
        for (auto it: mp){
            sortedMp.insert(pair<int, int>(it.second, it.first));
        }

        int maxTeam2Size = sortedMp.rbegin()->first;
        int minTeam1Size = mp.size()-1;
        
        // output
        int x = min(maxTeam2Size, minTeam1Size);
        
        if (maxTeam2Size - minTeam1Size >=2) ++x;

        cout << x << endl;

    }

    return 0;
}