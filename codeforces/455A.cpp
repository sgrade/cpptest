// A. Boredom
// NOT FINISHED

#include <iostream>
#include <map>
#include <algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;

    int tmp;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        cin >> tmp;
        ++mp[tmp];
    }



    return 0;
}
