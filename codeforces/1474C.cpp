// C. Array Destruction
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        vector<int> v(2 * n);
        for (auto &el: v) cin >> el;
        sort(v.begin(), v.end(), greater<int>());

        bool ans = true;

        vector<bool> removed(2 * n);

        if (n > 1){

            bool flag = false;

            int x = v[0];

            while (v.size() > 2) {

                auto found1 = find(v.begin(), v.end(), v[0] - v[1]);
                if (found1 != v.end()){
                    flag = true;
                    removed[1] = true;
                    auto found1_index = distance(v.begin(), found1);
                    removed[found1_index] = true;
                    x = v[found1_index];
                }

                if (flag){
                    
                }

            }
        
            for (int i = 0; i < 2 * n; ++i){
                for (int j = i + 1; j < 2 * n; ++j){
                    if ()
                    auto found = find(v.begin() + j + 1, v.end(), v[i] - v[j]);

                }

            }

        }
        
        

    }

    return 0;
}
