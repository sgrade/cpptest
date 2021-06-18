// C. Berpizza

#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct customComparator {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const
    {
        if (a.second > b.second) {
            return true;
        }
        return a.first < b.first;
    }
};


int main() {

    int q;
    cin >> q;

    // Editorial - https://codeforces.com/blog/entry/85951
    
    set<pair<int, int>> ids;
    set<pair<int, int>, customComparator> m;

    int q1, q2; 
    int num = 1;
    pair<int, int> current;
    
    while (q--) {

        cin >> q1;
        
        if (q1 == 1) {
            cin >> q2;
            ids.insert(pair(num, q2));
            m.insert(pair(num, q2));
            ++num;
        }

        else if (q1 == 2) {
            current = *begin(ids);
            cout << current.first << ' ';
            m.erase(current);
            ids.erase(begin(ids));
        }

        // q1 == 3
        else {
            current = *begin(m);
            cout << current.first << ' ';

            ids.erase(current);
            m.erase(begin(m));
        }
    }

    cout << endl;

    return 0;
}
