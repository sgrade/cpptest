// B. Divisors of Two Integers

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


bool divisorOfX(const int &aZero, const int &i) {
    return aZero % i;
}

int main(){

    int n;
    cin >> n;

    vector<int> all(n), divX, divY;

    for (int i=0; i<n; ++i){
        cin >> all[i];
    }
    sort(all.begin(), all.end(), greater<int>());

    remove_if(all.begin() + 1, all.end(), divisorOfX(all.front(), );

    int x = all[0];
    int y = all[1];

    cout << x << ' ' << y << endl;

    return 0;
}