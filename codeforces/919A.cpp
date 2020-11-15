// A. Supermarket

#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    float n, m, a, b;
    cin >> n >> m;
    
    cin >> a >> b;
    float ans = a * m / b;

    while(--n){
        cin >> a >> b;
        if (a * m / b < ans){
            ans = a * m / b;
        }
    }

    cout << setprecision(7) << ans << endl;

    return 0;
}
