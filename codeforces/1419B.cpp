// B. Stairs

#include <iostream>
#include <vector>
#include <map>
#include <limits>

using namespace std;


int main(){

    int t;
    cin >> t;

    vector<long long> v;
    v.push_back(1);

    long long cells;
    map<int, long long> mp;
    mp[1] = 1;

    int count = 1;
    for (int i=1; i<60+1; ++i){
        v.push_back(v[i-1] + i+1);

        if (i%2 != 0) continue;

        else{
            ++count;
            cells = mp[count-1] + v[i];
            mp.emplace(count, cells);
            cout << count << ": " << mp[count] << endl;
        }
    }



    return 0;
}