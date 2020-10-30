// A. The Rank

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comp(pair<int, int> x, pair<int, int> y){
    if (x.first > y.first){
        return true;
    }
    else if (x.first == y.first){
        return (x.second < y.second);
    }
    else return false;
}

int main(){

    int n;
    cin >> n;

    vector<pair<int, int>> v(n);
    for (int i=0; i<n; ++i){

        int tmp;
        pair<int, int> p(0, i);
        for (int j=0; j<4; ++j){
            cin >> tmp;
            p.first += tmp;
        }
        v[i] = p;

    }

    sort(v.begin(), v.end(), comp);

    auto found = find_if(v.begin(), v.end(), [](pair<int, int> x){
        return x.second == 0;
    });
    int ans = distance(v.begin(), found) + 1;

    cout << ans << endl;

    return 0;
}
