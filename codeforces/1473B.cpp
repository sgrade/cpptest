// B. String LCM

#include <iostream>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){

        string s, t;
        getline(cin >> ws, s);
        getline(cin >> ws, t);

        int sa, sb, ta, tb;
        sa = count(s.begin(), s.end(), 'a');
        sb = count(s.begin(), s.end(), 'b');
        ta = count(t.begin(), t.end(), 'a');
        tb = count(t.begin(), t.end(), 'b');

        string ans = "-1";
        
        if (sa == 0 && ta == 0){
            int len = lcm(sb, tb);
            ans = "";
            while(len--){
                ans += 'b';
            }
        }
        else if (sb == 0 && tb == 0){
            int len = lcm(sa, ta);
            ans = "";
            while(len--){
                ans += 'a';
            }
        }

        else {
            if (s.size() > t.size()) swap(s, t);
            // s is now not longer than t
            string subs = "";
            bool patternFound = false;
            for (int i = 0; !patternFound && i < s.size(); ++i){
                if (s[i] == t[i]){
                    subs += s[i];
                    //cout << subs << endl;
                    //cout << patternFound << endl;

                    bool divisible = true;

                    int cntS = 0, cntT = 0;
                    if (!subs.empty()){
                        if (s.size() % subs.size() == 0){
                            for (int i = 0; i < s.size() / subs.size(); ++i){
                                if (s.substr(i * subs.size(), subs.size()).compare(subs) != 0){
                                    divisible = false;
                                    break;
                                }
                                else ++cntS;
                            }
                        }
                        else divisible = false;
                        if (divisible && t.size() % subs.size() == 0){
                            for (int i = 0; i < t.size() / subs.size(); ++i){
                                if (t.substr(i*subs.size(), subs.size()).compare(subs) != 0){
                                    divisible = false;
                                    break;
                                }
                                else ++ cntT;
                            }
                        }
                        else divisible = false;

                        if (divisible){
                            patternFound = true;
                            int len = lcm(cntS, cntT);
                            ans = "";
                            while(len--){
                                ans += subs;
                            }
                        }
                    }

                }
                else break;
            }
        }

        cout << ans << endl;

    }

    return 0;
}
