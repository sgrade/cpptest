// A. Sign Flipping

#include <iostream>

using namespace std;


int main(){

    int t;
    cin >> t;

    while (t--){

        int n;
        cin >> n;

        // Editorial - https://codeforces.com/blog/entry/79731
        int tmp;
        for (int i=1; i<=n; ++i){
            cin >> tmp;
            if (i%2 != 0){
                cout << (tmp > 0 ? -tmp : tmp);
            }
            else {
                cout << (tmp < 0 ? -tmp : tmp);
            }
            cout << ' ';
        }
        cout << endl;
    }

    return 0;
}