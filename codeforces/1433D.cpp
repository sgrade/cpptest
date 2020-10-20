// D. Districts Connection

#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        bool ans = false;

        // <gang, indexes of it's towns>
        map<int, vector<int>> mp;

        int tmp;
        for (int i=0; i<n; ++i){
            cin >> tmp;
            // Indexing in the task is 1-based, so "+1"
            mp[tmp].push_back(i+1);
        }

        // Only one gang
        if (mp.size() == 1){
            cout << "NO\n";
        }
        // 2 or more gangs
        else {
            cout << "YES\n";
            
            map<int, vector<int>>::iterator it = mp.begin();
            int firstGang = it->first;
            ++it;
            int secondGang = it->first;

            // Roads to the first town of the first gang from all the towns of other gangs
            for (; it!=mp.end(); ++it){
                for (int i=0; i < it->second.size(); ++i){
                    cout << mp[firstGang][0] << ' ' << it->second[i] << endl;
                }
            }

            // Roads to the first town of the second gang from the towns of the first gang 
            // (all except the first, because the first towns of the first and second gangs are already connected)
            for (int i=1; i < mp[firstGang].size(); ++i){
                cout << mp[secondGang][0] << ' ' << mp[firstGang][i] << endl;
            }
        }

    }

    return 0;
}