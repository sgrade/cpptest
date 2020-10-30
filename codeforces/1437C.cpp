// C. Chef Monocarp
// NOT FINISHED

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int ans = 0;

        int n;
        cin >> n;

        if (n>1){
        
            map<int, int> mp;

            int tmp;
            for (int i=0; i<n; ++i){
                cin >> tmp;
                --tmp;
                ++mp[tmp];
            }

            int maxDuplicates = 1;
            for (auto el: mp){
                if (el.second > maxDuplicates) maxDuplicates = el.second;
            }
            
            vector<int> a(n+maxDuplicates, -1);
            
            for (auto el: mp){
                a[el.first] = el.first;
                --mp[el.first];
            }
            
            int range = 1;
            while(true ){

                int counter = 0;
                auto it = mp.begin();

                // erase empty
                while (it != mp.end()){
                    if (it -> second == 0){
                        ++counter;
                    }
                    else{

                        // place non-empty
                        int index = it -> first;
                        if ((index-range)>-1 && a[index-range] == -1) {
                            a[index-range] = index;
                            --mp[index];
                        }
                        else if (a[index+range] == -1){
                            a[index+range] = index;
                            --mp[index];
                        }
                        else if (a[index+range] != -1){
                            a.insert(a.begin()+index+range, 1, index);
                            --mp[index];
                        }
                        else ++range;
                    }
                    it++;
                }

                if (counter >= mp.size()) break;
            }
            
            for (int i=1; i<a.size(); ++i){
                if (a[i]!= -1 && a[i] < a[i-1]){
                    auto found = find(a.begin(), a.begin()+i-2, a[i]);
                    if (found != a.end()){
                        a.insert(found, 1, a[i]);
                        a.erase(a.begin()+i+1);
                    }
                    else {
                        swap(a[i-1], a[i]);
                    }
                }
            }

            for (int i=0; i<a.size(); ++i){
                if (a[i] == -1){
                    auto found = find_if(a.begin()+i, a.end(), [](const int x){
                        return x != -1;
                    });
                    if (found != a.end()){
                        int curTime = abs(*found - distance(a.begin(), found));
                        int candidateTime = abs(*found - i);
                        if (candidateTime < curTime){
                            swap(a[i], *found);
                        }
                    }
                }
            }
            

            for (int i=0; i<a.size(); ++i){
                if (a[i] != -1) ans += abs(a[i]-i);
            }

        }
        

        /*
        int ans = numeric_limits<int>::max();

        int maxDuplicates = 1;
        for (auto el: mp){
            if (el.second > maxDuplicates) maxDuplicates = el.second;
        }
        
        for (int x=0; x<(maxDuplicates + 2 - 1)/2; ++x){
            int curAns = 0;
            for (int i=0; i<n; ++i){
                curAns += abs(v[i] - (i+x));
            }
            if (curAns < ans) ans = curAns;
        }
        */

        /*
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
        */

        cout << ans << endl;
        
    }

    return 0;
}
