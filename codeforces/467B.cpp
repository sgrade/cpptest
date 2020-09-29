// B. Fedor and New Game

#include <iostream>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;


int main(){

    size_t n;
    int m, k;
    cin >> n >> m >> k;

    int tmp;
    vector< bitset<20> > v(m+1);
    for (int i=0; i<m+1; ++i){
        cin >> tmp;
        v[i] = bitset<20>(tmp);
    }

    int friends = 0;
    for (auto it=v.rbegin()+1; it != v.rend(); it++){
        auto result = v[m] ^ *it;
        if (result.count() <= k){
            ++friends;
        }
    }

    cout << friends << endl;

    return 0;
}