// A. Little Pony and Crystal Mine

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    int numOfD = -1;
    for (int i = 1; i < n+1; ++i){
        if (i <= (n + 2 - 1) / 2) numOfD += 2;
        else numOfD -= 2;
        int stars = (n - numOfD) / 2;
        cout << string(stars, '*') << string(numOfD, 'D') << string(stars, '*') << endl;
    }

    return 0;
}
