// A. Bear and Reverse Radewoosh

#include <iostream>

using namespace std;


int main() {

    int n, c;
    cin >> n >> c;

    int p[n], t[n];
    for (auto &el: p)
        cin >> el;
    for (auto &el: t)
        cin >> el;
    
    int limak = 0, radewoosh = 0;
    int time_limak = 0, time_radewoosh = 0;

    for (int i = 0; i < n; ++i) {
        time_limak += t[i];
        limak += max(0, p[i] - c * time_limak);

        time_radewoosh += t[n-1-i];
        radewoosh += max(0, p[n-1-i] - c * time_radewoosh);
    }

    if (limak > radewoosh) {
        cout << "Limak" << endl;
    }
    else if (radewoosh > limak) {
        cout << "Radewoosh" << endl;
    }
    else {
        cout << "Tie" << endl;
    }

    return 0;
}
