// B. Box Fitting

#include <iostream>
#include <algorithm>
#include <map>
#include <numeric>
#include <vector>

using namespace std;


map<int, int, greater <int>> mp;
int W;

// w - width, q - quantity
pair<int, int> place(const int w, const int q) {
    int cur_w, cur_h;
    cur_w = W / w;
    cur_h = q / cur_w;
    mp[w] = q % cur_w;

    return pair(cur_h, cur_w);
}

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n >> W;

        int tmp;
        for (int i = 0; i < n; ++i) {
            cin >> tmp;
            ++mp[tmp];
        }

        int ans = 0;

        // To store current 
        vector<int> box(100001, 0);
        vector<int>::iterator it_box;

        map<int, int>::iterator it_mp = mp.begin();
        int w, h, idx;
        int current_ans;
        while (it_mp != mp.end()) {
            w = it_mp->first;

            it_box = find_if(box.begin(), box.end(), [w](int w_left){
                return W - w >= w_left;
            });
            idx = distance(box.begin(), it_box);
            
            pair<int, int> p = place(W - box[idx], mp[w]);

            for (int i = idx; p.first > 0; ++i, --h) {
                box[i] += p.second;
            }
        }

        auto ans_it = find_if(box.begin(), box.end(), [](int x){
            return x == 0;
        });
        int anss = distance(box.begin(), ans_it) - 1;
        ans = max(1, anss);

        cout << ans << endl;
    }

    return 0;
}
