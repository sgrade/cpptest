// A. Cards for Friends

#include <iostream>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        long long w, h, n;
        cin >> w >> h >> n;

        long long sheets = 1;
        while (w > 1){
            if (w % 2 == 0) {
                w /= 2;
                sheets *= 2;
            }
            else break;
            if (sheets >= n) break;
        }

        while (sheets < n && h > 1){
            if (h % 2 == 0) {
                h /= 2;
                sheets *= 2;
            }
            else break;
            if (sheets >= n) break;
        }

        cout << (sheets >= n ? "YES" : "NO") << endl;

    }

    return 0;
}
