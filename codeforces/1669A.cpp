// A. Division?

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        int div;

        if (n <= 1399) div = 4;
        else if (n <= 1599) div = 3;
        else if (n <= 1899) div = 2;
        else div = 1;

        cout << "Division " << div << '\n';
    }

    return 0;
}
