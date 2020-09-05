// A. New Year and Naming

#include <iostream>
#include <string>

using namespace std;


int main(){

    int n, m;
    scanf("%d %d\n", &n, &m);

    string s[n+1];
    s[0] = "none";
    string t[m+1];
    t[0] = "none";

    for (int i=1; i<n+1; ++i){
        cin >> s[i];
    }
    for (int j=1; j<m+1; ++j){
        cin >> t[j];
    }

    int q;
    cin >> q;

    while (q--){

        int year;
        cin >> year;

        int ii = year % n;
        if (ii == 0) ii = n;
        int jj = year % m;
        if (jj == 0) jj = m;

        cout << s[ii] << t[jj] << endl;

    }

    return 0;
}