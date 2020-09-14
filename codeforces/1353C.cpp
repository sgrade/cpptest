// C. Board Moves

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/77373
        // n:                               1 -> 3 ->  5 ->  7 ->  9 -> ...
        // number of cells in the rows:     1 -> 8 -> 16 -> 24 -> 32 -> ...
        // distance for each cell:          0 -> 1 ->  2 ->  3 ->  4 -> ...
        // distance formula:                (n-1) / 2
        // we know, how int division works with odds in C++, so distance: n/2
        // number of cells in the rows:     1*0 + 8*1 + 16*2 + 24*3 + 32*4...
        // total distance for the cells:    0   + 8*1*1 + 8*2*2+ 8*3*3+ 8*4*4
        // If i is the distance and it increments by 1 with each layer
        //                                  0   + 8*i*i + 8*(i+1)*(i+1)...

        long long output = 0;

        for (long long i=1; i <= n/2; ++i){
            output += i*i;
        }

        cout << 8 * output << endl;

    }

    return 0;
}