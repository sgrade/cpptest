// C. Chef Monocarp
// NOT FINISHED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        map<int, int> mp;

        int tmp;
        for (int i=0; i<n; ++i){
            cin >> tmp;
            ++mp[tmp];
        }

        int ans = 0;
        // Supplementary array with inputs for the answer
        // Indexing starts from 1, so 200 + 1
        vector<int> a(201, -1);

        int range = 0;
        while(!mp.empty()){
            auto it = mp.begin();
            while (it != mp.end()){
                if (it -> second == 0){
                    it = mp.erase(it);
                }
                else{
                    it++;
                }
            }
            for (auto el: mp){
                int index = el.first;
                if (a[index] == -1){
                    a[index] = 0;
                    --mp[index];
                }
                if (mp[index]>0 && (index-range)>0 && a[index-range] == -1) {
                    a[index-range] = range;
                    --mp[index];
                }
                if (mp[index]>0 && (index+range)<201 && a[index+range] == -1){
                    a[index+range] = range;
                    --mp[index];
                }
            }
            
            ++range;
            
        }
        
        for (int i=0; i<a.size(); ++i){
            if (a[i] != -1) ans += a[i];
        }

        cout << ans << endl;
        
    }

    return 0;
}
