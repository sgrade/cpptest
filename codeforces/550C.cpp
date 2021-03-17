// C. Divisibility by Eight

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string s;
    getline(cin, s);

    bool ans = false;
    
    // Editorial - https://codeforces.com/blog/entry/18329
    int tmp = 0;
    string str;
    while(tmp < 1000)
    {
        str = to_string(tmp);

        size_t idx = 0;
        int offset = 0;
        for (int i = 0; idx != string::npos && i < str.size(); ++i)
        {
            idx = s.find(str[i], offset);
            offset = idx + 1;
        }

        if (idx != string::npos)
        {
            ans = true;
            break;
        }

        tmp += 8;
    }

    cout <<  (ans ? "YES\n" + str: "NO") << endl;

    return 0;
}
