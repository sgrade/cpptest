// A. Add Candies

#include <iostream>


using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/82067
        cout << n << endl;
        for (int i = 1; i < n+1; ++i){
            cout << i << ' ';
        }
        cout << endl;
    }

    return 0;
}
