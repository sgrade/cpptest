// 

#include <iostream>
#include <bitset>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        unsigned long a, b;
        cin >> a >> b;

        bitset<32> bsA(a);
        // cout << bsA.to_ullong() << endl;
        bitset<32> bsB(b);
        // cout << bsB.to_ullong() << endl;

        bitset<32> bsX = (bsA &= bsB);
        unsigned long x = bsX.to_ulong();
        // cout << bsX.to_ullong() << endl;

        // unsigned long long ans = (bsA^=bsX).to_ullong();
        unsigned long long ans = (a^=x) + (b^=x);

        cout << ans << endl;

    }

    return 0;
}
