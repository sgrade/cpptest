// A. Add Candies
// NOT FINISHED

#include <iostream>


using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;

        // Ariphmetic progression: 1, 2, 3, ..., (n-1)
        cout << n * (n-1) / 2 << endl;
        for (int i = n; i > 1; --i){
            for (int j = i; j > 1; --j){
                cout << i << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
