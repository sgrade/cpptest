// C. Chef Monocarp
// NOT FINISHED: passes simple test cases, but not advanced ones

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

        map<int, int> mp;
            int tmp;
            for (int i=0; i<n; ++i){
                cin >> tmp;
                --tmp;
                ++mp[tmp];
        }

        if (n>1){
    
            int maxDuplicates = 1;
            for (auto el: mp){
                if (el.second > maxDuplicates) maxDuplicates = el.second;
            }
            
            // At which time we take which dish
            vector<int> a(n*4, -1);
            
            // Initial placement
            while(true ){

                int counter = 0;
                auto it = mp.begin();

                while (it != mp.end()){
                    if (it -> second == 0){
                        ++counter;
                    }
                    else{
                        while(it -> second != 0){
                            int index = it -> first;
                            if (a[index] == -1){
                                a[index] = index;
                                --mp[index];
                            }
                            else {
                                auto foundDown = find(a.rbegin()+(a.size()-index-1), a.rend(), -1);
                                int TMP = *foundDown;
                                int distanceDown = numeric_limits<int>::max();
                                if (foundDown != a.rend()){
                                    distanceDown = distance(a.rbegin()+(a.size()-index-1), foundDown);
                                }
                                auto foundUp = find(a.begin()+index+1, a.end(), -1);
                                int distanceUp = distance(a.begin()+index, foundUp);
                                if (distanceUp > distanceDown){
                                    a[index - distanceDown] = index;
                                }
                                else {
                                    a[index + distanceUp] = index;
                                }
                                --mp[index];
                            }
                        }
                    }
                    it++;
                }

                if (counter >= mp.size()) break;
            }
           
            // Further optimization
            int counter = 0;
            while(true){
                int currentAns=0, candidateAns=0;

                auto firstNegative = find(a.begin()+counter, a.end(), -1);

                auto firstPositive = find_if(firstNegative, a.end(), [](int x){
                    return x != -1;
                });

                auto negativeAfterPositive = find(firstPositive, a.end(), -1);

                if (firstNegative != a.end() && firstPositive != a.end()){
                    int indexFirstPositive = distance(a.begin(), firstPositive);
                    int indexNegativeAfterPositive = distance(a.begin(), negativeAfterPositive);

                    for (int i=indexFirstPositive; i<indexNegativeAfterPositive; ++i){
                        candidateAns += abs(a[i]-(i-1));
                        currentAns += abs(a[i]-(i));
                    }
                    if (candidateAns < currentAns){
                        firstNegative = a.erase(firstNegative);
                    }
                
                    ++counter;
                }
                else break;
            }

            // Counting answer
            for (int i=0; i<a.size(); ++i){
                if (a[i] != -1) ans += abs(a[i]-i);
            }

        }
        
        cout << ans << endl;
        
    }

    return 0;
}
