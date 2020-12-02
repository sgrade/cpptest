// B. Jumps

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int x;
        cin >> x;

        // Based on https://codeforces.com/contest/1455/submission/100058627
        int k = 0;
        while(x > 0){
            ++k;
            x -= k;
        }

        // Why "x == -1" is explained here
        // https://codeforces.com/blog/entry/85186?#comment-728523
        cout << k + (x == -1) << endl;
    }

    return 0;
}
