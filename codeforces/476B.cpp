// B. Dreamoon and WiFi

#include <iostream>
#include <string>

using namespace std;

string s1, s2;
int n;
int target_position = 0;
double times_reached_end, times_reached_target;

void move(int i, int current_position) {

    // Reached the end of s2
    if (i == n) {
        ++times_reached_end;
        if (current_position == target_position) {
            ++times_reached_target;
        }
        return;
    }

    // Recursively trying each possible scenario from i to the end
    if (s2[i] == '+') {
        move(i+1, current_position+1);
    }
    else if (s2[i] == '-') {
        move(i+1, current_position-1);
    }
    else {
        move(i+1, current_position+1);
        move(i+1, current_position-1);
    }
}


int main() {

    cin >> s1 >> s2;

    // Idea from https://codeforces.com/contest/476/submission/8185687

    n = size(s1);

    for (auto &ch: s1) {
        if (ch == '+') {
            ++target_position;
        }
        else {
            --target_position;
        }
    }

    move(0, 0);

    double ans = times_reached_target / times_reached_end;

    cout.precision(9);
    cout << ans << endl;

    return 0;
}
