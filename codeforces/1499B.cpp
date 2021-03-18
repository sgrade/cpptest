// B. Binary Removals

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;


int main(){

    int t;
    cin >> t;

    string s;

    while(t--)
    {
        getline(cin >> ws, s);

        int zeroes = count(s.begin(), s.end(), '0');
        int ones = s.size() - zeroes;

        bool ans = true;

        if (min(zeroes, ones) > 0)
        {
            auto ii = s.find("11");
            if (ii != string::npos)
            {
                auto z = s.find('0', ii);
                if (z != string::npos)
                {
                    auto zz = s.find("00", z);
                    {
                        if (zz != string::npos)
                        {
                            ans = false;
                        }
                    }
                }
            }
        }

        cout << (ans ? "YES" : "NO") << endl;

    }

    return 0;
}
