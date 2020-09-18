// A. Football

#include <iostream>
#include <string>
#include <set>

using namespace std;


int main(){

    int n;
    cin >> n;
    
    string team1Name;
    getline(cin >> ws, team1Name);

    string team2Name;

    int scoreTeam1 = 1;
    int scoreTeam2 = 0;
    
    string winner = team1Name;
    
    if (n>1){

        string s;
        // we already scanned one of n, thus --n instead of n--
        while (--n){    

            getline(cin, s);
            if (s == team1Name) ++scoreTeam1;
            else {
                ++scoreTeam2;
                team2Name = s;
            }

        }

        winner = scoreTeam1 > scoreTeam2 ? team1Name : team2Name;
    }

    cout << winner << endl;

    return 0;
}