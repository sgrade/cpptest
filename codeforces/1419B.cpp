// B. Stairs

#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <iterator>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    vector<long long> tests;
    while (t--){
        long long x;
        cin >> x;
        tests.push_back(x);
    }

    long long cells = 0;
    map<int, long long> mp;

    int niceStaircases = 0;
    long long n = 1;      // number of stairs; number of disjoint squares
    int p = 1;      // increment to n
    while (cells <= *max_element(tests.begin(), tests.end())){

        cells += n*(n+1) / 2;
        ++niceStaircases;
        p *= 2;
        n += p;

        // cout << niceStaircases << ": " << cells << endl;
        mp.emplace(niceStaircases, cells);
    }

    for(int i=0; i<tests.size(); ++i){

        for (auto it: mp){
            if (it.second == tests[i]){
                cout << it.first << endl;
                break;
            }
            else if (it.second > tests[i]){
                cout << it.first -1 << endl;
                break;
            }
        }
    }

    return 0;
}