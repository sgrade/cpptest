// C. Save More Mice

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;
    
    while (t--) {
        
        int n, k;
        cin >> n >> k;

        vector<int> x(k);
        for (auto &el: x) {
            cin >> el;
        }

        sort(begin(x), end(x));

        int ans = 0;
        int cat = 0, cur_x = k-1;
        
        while (cur_x > -1) {
        
            if (cat < x[cur_x]) {
                ++ans;
                cat += n - x[cur_x];
            }
            
            else {
                break;
            }
            
            --cur_x;
        }

        cout << ans << endl;
    }

    return 0;
}
