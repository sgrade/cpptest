// B. Ilya and Queries

#include <iostream>
#include <string>
#include <numeric>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    int n = s.size();

    int m;
    cin >> m;

    // Analyze the string once. Will use the data in the queries.
    bool a[n] = {0};
    char prev=s[0];
    for (int i=1; i<n; ++i){
        if (s[i] == prev){
            a[i-1] = true;
        }
        else a[i-1] = false;
        prev = s[i];
    }
    // We don't need a[n-1] in calculation. Do it just to make the code clean.
    a[n-1] = 0;

    // Above is not enough - time limit exceeded
    // So - https://codeforces.com/blog/entry/7826
    int sum[n] = {0};
    sum[0] = a[0];
    for (int i=1; i<n; ++i){
        sum[i] = sum[i-1] + a[i];
    }    

    while (m--){

        int l, r;
        cin >> l >> r;

        // -1 because indexing in the task start from 1, but in the arrays from 0
        // -1 because according to the query r is not included
        int right = r-2 < 0 ? 0 : sum[r-2];
        int left = l-2 < 0 ? 0 : sum[l-2];
        
        int output = right - left;
        cout << output << endl;
    }

    return 0;
}