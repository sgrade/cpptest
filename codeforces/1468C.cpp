// C. Berpizza
// Time limit exceeded on test 17

#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;


int main() {

    int q;
    cin >> q;

    deque<pair<int, int>> dq;
    multimap<int, int, greater<int>> m;

    int q1, q2, num = 1;
    while (q--) {

        cin >> q1;
        
        if (q1 == 1) {
            cin >> q2;
            dq.push_back(pair(q2, num));
            m.insert(pair(q2, num));
            ++num;
        }

        else if (q1 == 2) {
            cout << begin(dq)->second << ' ';

            int current_m = begin(dq)->first;
            auto it = find_if(begin(m), end(m), [current_m](const pair<int, int> p){
                return p.first == current_m;
            });

            dq.erase(begin(dq));
            m.erase(it);
        }

        // q1 == 3
        else {
            cout << begin(m)->second << ' ';

            int current_m = begin(m)->first;
            auto it = find_if(begin(dq), end(dq), [current_m](pair<int, int> p){
                return p.first == current_m;
            });

            dq.erase(it);
            m.erase(begin(m));
        }

    }

    cout << endl;

    return 0;
}
