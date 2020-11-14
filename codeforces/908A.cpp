// A. New Year and Counting Cards

#include <iostream>
#include <string>
#include <ctype.h>
#include <algorithm>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char even[] = {'0', '2', '4', '6', '8'};
    
    int ans = 0;
    for (int i = 0 ; i < s.size(); ++i){
        bool isVowel = false;
        if (find(begin(vowels), end(vowels), s[i]) != end(vowels)) isVowel = true;
        bool isOdd = false;
        if (!isVowel){
            if (find(begin(even), end(even), s[i]) == end(even)) isOdd = true;
        }
        bool isd = isdigit(s[i]);
        if (isVowel || (isdigit(s[i]) && isOdd)){
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}
