// C1. Potions (Easy Version)

#include <iostream>
#include <set>

using namespace std;


int main() {

    int n;
    cin >> n;

    multiset<int> mst;

    long long health = 0LL;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        if (health + tmp < 0) {
            if (mst.empty()) {
                continue;
            }
            else {
                if (*mst.begin() < tmp) {
                    health -= *mst.begin();
                    mst.erase(mst.begin());
                }
                else {
                    continue;
                }
            }
        }

        health += tmp;
        mst.insert(tmp);
    }

    cout << mst.size() << endl;

    return 0;
}