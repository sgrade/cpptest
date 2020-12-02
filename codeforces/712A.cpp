// A. Memory and Crow

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> a(n), ans(n);
    for (auto &el: a) cin >> el;

    ans[n-1] = a[n-1];
    for (int i=n-2; i>-1; --i){
        ans[i] = a[i] + a[i+1];
    }

    for (auto el: ans) cout << el << ' ';
    cout << endl;

    return 0;
}
