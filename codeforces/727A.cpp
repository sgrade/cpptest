// A. Transformation: from A to B

#include <iostream>
#include <vector>

using namespace std;


int x;
vector<int> output;

bool check() {

    if ((x - 1) % 10 == 0) {
        x -= 1;
        x /= 10;
        output.push_back(x);
        return true;
    }
    if (x % 2 == 0) {
        x /= 2;
        output.push_back(x);
        return true;
    }

    return false;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    cin >> a >> b;

    // Editorial - https://codeforces.com/blog/entry/47773

    bool ans = true;

    if (a != b) {

        x = b;
        output.push_back(b);
        bool go = true;
        while (go) {
            go = check();
            if (x <= a) break;
        }

        if (x != a) {
            ans = false;
        }        
    }

    if (ans) {
        cout << "YES\n";
        cout << output.size() << '\n';
        for (int i = output.size() - 1; i > -1; --i) {
            cout << output[i] << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "NO\n";
    }

    return 0;
}
