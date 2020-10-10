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

    int x = 0;
    int y = all[0];
    for (int i=1; i<n; ++i){
        if (y % all[i] != 0){
            x = all[i];
            break;
        }
    }
    if (x == 0){
        x = all[1];
    }

    cout << y << ' ' << x << endl;

    return 0;
}