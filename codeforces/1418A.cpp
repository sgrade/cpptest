// A. Buying Torches

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        long long x, y, k;
        cin >> x >> y >> k;

        long long trades = 0;
        long long sticks = 1;
        long long coals = 0;
        
        // buying (k(sticks to make torch) + k*y(to buy coals)) sticks
        long long sticksRequired = k + k*y;
        // First stick is not aquired through trades (is already given in the beginning): sticksRequired-1
        // We lose one stick every trade: x-1
        trades = (sticksRequired-1)/(x-1);
        // We cannot do partial trade (part of x)
        if ((sticksRequired-1) % (x-1) != 0){
            ++ trades;
        }
        
        // buying coals
        trades += k;

        cout << trades << endl;

    }

    return 0;
}