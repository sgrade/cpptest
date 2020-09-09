// A. String Task

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>       // tolower

using namespace std;


int main(){

    string s;
    cin >> s;

    char vowels[12] = {'A', 'a', 'O', 'o', 'Y', 'y', 'E', 'e', 'U', 'u', 'I', 'i'};

    string output;
    for (int i=0; i<s.size(); ++i){

        if (find(vowels, vowels+12, s[i]) == vowels+12){
            output += '.';
            output += tolower(s[i]);
        }

    }

    cout << output << endl;

    return 0;
}