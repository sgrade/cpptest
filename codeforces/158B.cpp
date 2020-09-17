// B. Taxi

#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){

    int n;
    cin >> n;

    int tmp;
    unordered_map<int, int> mp;
    for (int i=0; i<n; ++i){
        cin >> tmp;
        mp[tmp] += 1;
    }

    int taxis = 0;

    // Packing full cars (no empty seats)
    taxis += mp[4];

    taxis += mp[2]/2;
    mp[2] %= 2;

    int threePlusOne = min(mp[3], mp[1]);
    taxis += threePlusOne;
    mp[1] -= threePlusOne;
    mp[3] -= threePlusOne;
   
    // Packing the rest
    while (mp[3]>0 || mp[2]>0 || mp[1]>0){

        int emptySeats = 4;
        
        if (emptySeats >=3 && mp[3]>0){
            emptySeats -= 3;
            --mp[3];
        }
        while (emptySeats >=2 && mp[2]>0){
            emptySeats -=2;
            --mp[2];
        }
        while (emptySeats >= 1 && mp[1]>0){
            --emptySeats;
            --mp[1];
        }
        if (emptySeats < 4) {
            ++taxis;
        }
        else break;

    }

    cout << taxis << endl;

    return 0;
}