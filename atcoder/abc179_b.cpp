// B - Go to Jail

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    bool output = false;

    int curDoubletsInARow = 0;
    int maxDoubletsInARow = 0;
    int d1, d2;
    for (int i=0; i<n; ++i){

        cin >> d1 >> d2;
        if (d1 == d2){
            ++curDoubletsInARow;
            if (curDoubletsInARow > maxDoubletsInARow){
                ++maxDoubletsInARow;
                if (maxDoubletsInARow == 3){
                    output = true;
                    break;
                }
            }
        }
        else curDoubletsInARow = 0;
    }

    cout << (output ? "Yes" : "No") << endl;

    return 0;
}