// B. Substring Removal Game

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        string s;
        cin >> s;

        vector<int> v;

        int score = 0;

        if (s.size() == 1) score = s[0]-48 == 1 ? 1 : 0;

        else {

            int count = 0;
            for (unsigned i = 0; i < s.size(); ++i)
            {
                if ( s[i]-48 == 1 ) 
                {
                    count += 1;

                    // if last element in string == 1
                    if (i == s.size() - 1 && count > 0)
                        v.push_back(count);
                }

                else 
                {
                    if (count > 0) 
                        v.push_back(count);
                    count = 0;
                }
            }
        }

        sort(v.begin(), v.end(), greater<int>());

        for (unsigned i=0; i < v.size(); i+=2)
            score += v[i];

        cout << score << endl;

    }

    return 0;
}