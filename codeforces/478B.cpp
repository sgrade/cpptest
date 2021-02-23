// B. Random Teams

#include <iostream>
#include <algorithm>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    int people_in_team;
    int people_in_full_team;

    // Calculating min
    people_in_full_team = (n + m - 1) / m;
    long long mn;
    // Pairs in one full team
    mn = 1LL * people_in_full_team * (people_in_full_team - 1) / 2;
    // Will all teams be full?
    int rem = n % m;
    // All teams are full
    if (rem == 0) 
    {
        mn *= m;
    }
    // Not all teams are full  
    else 
    {
        // Formula from the editorial - https://codeforces.com/blog/entry/14307
        int full_teams = n % m;
        mn *= full_teams;
        // number of smaller teams
        int smaller_teams = m - full_teams;
        int people_in_small_team = n / m;
        long long pairs_in_smaller_team = 
            1LL * people_in_small_team * (people_in_small_team - 1) / 2;
        mn += smaller_teams * pairs_in_smaller_team;
    }

    // Calculating max
    people_in_team = n - (m - 1);
    long long mx = 1LL * people_in_team * (people_in_team - 1) / 2;
    
    cout << min(mn, mx) << ' ' << max(mn, mx) << endl;

    return 0;
}
