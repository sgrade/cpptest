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
        if (all[0] == all[1]){
            x = all[1];
        }
        else if (all[n-1] == 1 && all[n-2] == 1){
            x = all[0];
        }
        else {
            x = 1;
        }
    }
    
    cout << y << ' ' << x << endl;

    return 0;
}