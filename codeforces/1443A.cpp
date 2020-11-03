// A. Kids Seating

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;


int gcd(int a, int b) { 
	if (b == 0) {
		return a;
	} 
	return gcd(b, a % b);  
}


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        set<int> dp;
        for (int i=4*n; i>0; --i){
            bool tryNextI = false;
            if (!tryNextI){
                for (auto el: dp){
                    if (i % el == 0 || el % i == 0 || gcd(i, el) == 1){
                        tryNextI = true;
                        break;
                    }
                }
                if(!tryNextI){
                    dp.insert(i);
                }
            }
            else continue;
        }

        for(auto el: dp){
            cout << el << ' ';
            --n;
            if (n == 0) break;
        }

        cout << endl;

    }

    return 0;
}
