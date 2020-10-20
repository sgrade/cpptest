// C. Dominant Piranha

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;
    
    while(t--){

        int n;
        cin >> n;

        int maxP = 0;
        int maxPIndex;
        set<int> st;
        vector<int> v;

        int prev = 0;
        int prevPrev = 0;

        bool ans = false;

        int tmp;
        for (int i=0; i<n; ++i){

            cin >> tmp;
            st.insert(tmp);
            v.push_back(tmp);

            if (tmp > maxP){
                maxP = tmp;
            }
        }

        if (st.size()>1){
            for (int i=0; i<n; ++i){
                if (v[i] < maxP){
                    if ((i>0 && v[i-1]==maxP)){
                        ans = true;
                        // index starts from 1, so +1
                        maxPIndex = i-1 + 1;
                        break;
                    }
                    else if(i<n-1 && v[i+1]==maxP){
                        ans = true;
                        // index starts from 1, so +1
                        maxPIndex = i+1 + 1;
                        break;
                    }
                }
            }
        }       

        cout << (ans ? maxPIndex : -1) << endl;
        
    }

    return 0;
}