// B. Card Constructions

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    // Total num of card for a pyramid, e.g. height of 4:
    // 1*3 + 2*3 + 3*3 + 4*3 - 4
    // 1*3 + 2*3 + 3*3 + 4*3 is if all levels had bottom cards
    // -4 because bottom level doesn't have cards
    
    // <height, number of cards>
    map<int, int> dp = {
        {1, 2},
        {2, 7},
        {3, 15}
    };

    while(t--){

        int n;
        cin >> n;

        // build dp until n
        int newHeight, prevNumOfCards;
        while (dp.rbegin()->second <= n){
            newHeight = dp.rbegin()->first + 1;
            prevNumOfCards = dp.rbegin()->second;
            // For each level we need to add (h*3 - 1) cards
            // h*3: because we add one "triangle" of cards on each level
            // -1:  because the bottom level doesn't have a card on bottom
            dp.insert(pair<int, int>(newHeight, prevNumOfCards + newHeight*3 - 1));
        }
        // use pre-built dp
        int ans = 0;
        while (n >= 2) {
            for (auto rit=dp.rbegin(); rit!=dp.rend(); rit++){
                // It might be that after the substraction cards = n
                // so we need while (up to two repetitions) instead of if (one repetition)
                while (rit->second <= n){
                    n -= rit->second;
                    ++ans;
                }
            }
        }
        cout << ans << endl;
    }

}