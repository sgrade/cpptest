// A. Love "A"

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    int ans = 1;
    int numOfA = count(s.begin(), s.end(), 'a');

    int sHalf = s.size()/2;

    if (numOfA > sHalf){
        ans = s.size();
    }
    else{
        ans = numOfA*2 - 1;
    }

    cout << ans << endl;

    return 0;
}
