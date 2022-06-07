// https://github.com/guardian/coding-exercises/tree/main/election-results
// NOT FINISHED

/*
Cardiff West, 11014, C, 17803, L, 4923, UKIP, 2069, LD
Islington South & Finsbury, 22547, L, 9389, C, 4829, LD, 3375, UKIP, 3371, G, 309, Ind
*/

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// String to number
ll string_to_number(string s) {
    ll num = 0;
    // TODO: Check for overflow
    int cnt = 1;
    for (char& c: s) {
        num += num * cnt + (c - '0');
        cnt *= 10;
    }
    
    return num;
}


// TODO: check overflows
map<string, map<string, ll>> parse(const string& s) {
    map<string, map<string, ll>> output;

    size_t left = 0, right;
    string subs;

    right = s.find(',');

    string constituency = s.substr(left, right);
    
    pair<string, ll> votes;
    string tmp;
    while (true) {

        // parsing votes
        left = right + 2;
        right = s.find(',', left);
        if (right != string::npos) {
            tmp = s.substr(left, right);
            votes.second = string_to_number(tmp);
        }

        // parsing party code
        left = right + 2;
        right = s.find(',', left);
        tmp = s.substr(left, right);
        votes.first = tmp;

        if (output.find(votes.first) != output.end()) {
            output[constituency][votes.first] += votes.second;
        }
        
    }
}


int main() {

    int n = 2;

    string s;

    while (n--) {    
        cin >> s;

        
    }

    return 0;
}
