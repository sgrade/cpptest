// A. Far Relative’s Birthday Cake

#include <iostream>
#include <string>
#include <map>

using namespace std;


// number of combinations - https://en.wikipedia.org/wiki/Combination
// combinations formula is simplified, taking into account that k = 2
// so (n! / (n-2)!) is simplified to (n*(n-1))
long long combs(long long n){
    return n * (n-1) / 2;
}

int main(){

    int n;
    cin >> n;

    map<int, long long> rows;
    map<int, long long> columns;

    long long ans = 0;

    string tmp;
    
    for (int i=0; i<n; ++i){
        getline(cin >> ws, tmp);
        for (int j=0; j<n; ++j){
            if (tmp[j] == 'C'){
                ++rows[i];
                ++columns[j];
            }
        }
    }

    for (long long i=0; i<n; ++i){
        if (rows[i] > 1) ans += combs(rows[i]);
        if (columns[i] > 1) ans += combs(columns[i]);
    }

    cout << ans << endl;

    return 0;
}