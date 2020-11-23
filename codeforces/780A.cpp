// A. Andryusha and Socks

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    size_t maxSocks = 0;
    
    set<int> table;
    int tmp;
    for (int i=0; i<n*2; ++i){
        cin >> tmp;
        if (table.find(tmp) != table.end()){
            table.erase(tmp);
        }
        else{
            table.insert(tmp);
            maxSocks = max(maxSocks, table.size());
        }
    }

    cout << maxSocks << endl;

    return 0;
}
