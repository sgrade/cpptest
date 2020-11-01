// A. Game

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &it: v){
        cin >> it;
    }
    sort(v.begin(), v.end());

    cout << v[(n-1)/2] << endl;

    return 0;
}
