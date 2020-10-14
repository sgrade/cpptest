// B. Divisors of Two Integers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> all(n), divX, divY;

    for (int i=0; i<n; ++i){
        cin >> all[i];
    }
    sort(all.begin(), all.end(), greater<int>());

    // Editorial - https://codeforces.com/blog/entry/64751
    int x = all[0];
    for (int i=1; i<=all[0]; ++i){
        if (all[0] % i == 0){
            all.erase(find(all.begin(), all.end(), i));
        }
    }

    int y = all[0];

    cout << x << ' ' << y;
    cout << endl;

    return 0;
}