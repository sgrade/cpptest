// C. Canine poetry
// NOT FINISHED

#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <list>
#include <numeric>

using namespace std;

bool isPalindrome(const string &s){
    bool ans = true;
    for (int i = 0; ans && i < s.size() / 2 + 1; ++i){
        if (s[i] != s[s.size()-1-i]) ans = false;
    }
    return ans;
}

string pickNext(string &str){
    if (str.empty()){
        std::string alphabet = "abcdefghijklmnopqrstuvwxyz";
	}
	string tmp;
	tmp += str[0];
	str.erase(0, 1);
    return tmp;
}


int main(){

    int t;
    cin >> t;

    while(t--){

        string s;
        getline(cin >> ws, s);

        int ans = 0;

        if (s.size() > 1){

            vector<char> v;
            map<char, int> mp;
            string alphabet = "abcdefghijklmnopqrstuvwxyz";

            for (auto ch: s){
                ++mp[ch];
                if (mp[ch] == 1) {
                    v.push_back(ch);
                    auto found = alphabet.find(ch);
                    alphabet.erase(found, 1);
                }
            }

            vector<char> checked;
            for (auto ch: v){
                if (find(checked.begin(), checked.end(), ch) == checked.end()){
                    checked.push_back(ch);

                    if (mp[ch] > 1){
                        int i = mp[ch];
                        while(i > 1){
                            auto first = s.find_first_of(ch);
                            auto next = s.find(ch, first+1);
                            string sTmp = s.substr(first, next - first + 1);
                            // cout << sTmp << endl;
                            if (isPalindrome(sTmp)) {
                                // cout << sTmp << endl;
                                s.replace(next, 1, pickNext(alphabet));
                                ++ans;
                                // cout << s << endl;
                            }
                            --i;
                        }

                    }

                }
                
            }

        }
        

        cout << ans << endl;

    }

    return 0;
}
