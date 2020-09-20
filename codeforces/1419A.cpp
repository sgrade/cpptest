// A. Digit Game
 
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
 
using namespace std;
 
 
int main(){
 
    int t;
    cin >> t;
 
    while (t--){
 
        // Parsing the input
        int n;
        cin >> n;
 
        string s;
        getline(cin >> ws, s);
        
        // Raze can choose digits in odd positions; Breach - even
        vector<int> oddPos;
        vector<int> evenPos;
        
        int tmp;
        for (int i=0; i<n; ++i){
            tmp = (int)s[i] - 48;
            // indexing in the task start from 1;
            if (i%2 == 0) oddPos.push_back(tmp);
            else evenPos.push_back(tmp);
        }

        // First factor in game result
        bool nIsOdd = n%2==0 ? false : true;
        
        // Second factor in game result
        bool oddInOdd = false;
        for (auto it: oddPos){
            if (it%2!=0) {
                oddInOdd = true;
                break;
            }
        }
        
        bool evenInEven = false;
        for (auto it: evenPos){
            if (it%2 == 0) {
                evenInEven = true;
                break;
            }
        }

        // Checking game result
        int output;
        if (nIsOdd && oddInOdd) output = 1;
        else if (nIsOdd && !oddInOdd) output = 2;
        else if (!nIsOdd && evenInEven) output = 2;
        else if (!nIsOdd && !evenInEven) output = 1;
    
        cout << output << endl;
 
    }
 
    return 0;
}