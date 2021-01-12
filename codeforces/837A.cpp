// A. Text Volume

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    getline(cin >> ws, s);

    // https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/
    istringstream iss(s);
    vector<string> v((istream_iterator<string> (iss)), istream_iterator<string>() );

    int maxVolume = 0;
    for (string word: v){
        int volume = 0;
        for (auto c: word){
            if (isupper(c)) ++volume;
        }
        if (volume > maxVolume) maxVolume = volume;
    }

    cout << maxVolume << endl;

    return 0;
}
