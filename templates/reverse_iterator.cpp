#include <bits/stdc++.h>

using namespace std;


int main() {

    vector<int> v = {0, 1, 2, 3, 4};
    vector<int>::reverse_iterator rit = find(v.rbegin(), v.rend(), 2);
    cout << *rit << endl;   // 2
    cout << *rit.base() << endl;    // 3
    cout << *(rit.base() - 1) << endl;  // 2
    cout << *(rit.base() + 1) << endl;  //  4
    cout << distance(v.begin(), rit.base()) - 1 << endl;    // 2    

    return 0;
}
