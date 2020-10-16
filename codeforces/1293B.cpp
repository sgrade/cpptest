// B. JOE is on TV!

#include <iostream>

using namespace std;


int main(){

    float n;
    cin >> n;

    // https://en.wikipedia.org/wiki/Divergent_series

    // Editorial - https://codeforces.com/blog/entry/73051
    
    float ans = 0;
    for (float i=1; i<=n; ++i){
        ans += 1 / i;
    }

    cout << ans << endl;

    return 0;
}