// A. Between the Offices

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    int fromS = 0, fromF = 0;

    char prev = s[0];
    for (int i=1; i<s.size(); ++i){
        if (s[i] != prev){
            if (prev == 'S') ++fromS;
            else ++fromF;
        }
        prev = s[i];
    }

    cout << (fromS > fromF ? "YES\n" : "NO\n");

    return 0;
}
