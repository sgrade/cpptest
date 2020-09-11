// A. Road To Zero

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        long long x, y;
        cin >> x >> y;

        long long a, b;
        cin >> a >> b;

        long long sum = 0;

        x = abs(x);
        y = abs(y);

        long long maxSecondOperations = min(x, y);

        if (a*2 > b){
            sum += maxSecondOperations * b;
            x -= maxSecondOperations;
            y -= maxSecondOperations;
        }
        sum += (x+y) * a;

        cout << sum << endl;
    
    }

    return 0;
}
