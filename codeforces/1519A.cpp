// A. Red and Blue Beans

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int t;
    cin >> t;

    while (t--) {

        int r, b, d;
        cin >> r >> b >> d;

        if (r > b) {
            swap(r, b);
        }
        
        bool ans = false;
        
        int packets = r;
        int rem = b - r;
        int rem_per_packet = (rem + packets - 1) / packets;
        if (rem_per_packet <= d) {
            ans = true;
        }
 
        cout << (ans ? "YES" : "NO") << endl;
 
    }

    return 0;
}
