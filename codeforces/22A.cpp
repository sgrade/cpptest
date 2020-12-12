// A. Second Order Statistics

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    set<int> a;
    int tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        a.insert(tmp);
    }

    if (a.size() > 1){   
        set<int>::iterator it = a.begin();
        ++it;
        cout << *it << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
