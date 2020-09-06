// A. One-dimensional Japanese Crossword

#include <iostream>
#include <string>
#include <list>

using namespace std;


int main(){

    int n;
    cin >> n;

    string s;
    cin >> s;

    // Outputs
    int k=0;
    list<int> sizes;

    char prev = s[0];
    int curSize = 0;
    for (int i=0; i<n; ++i)
    {
        if(s[i]=='B')
        {
            ++curSize;
            if (i==n-1) 
            {
                sizes.push_back(curSize);
                ++k;
            }
        }
        else
        {
            if (curSize > 0)
            {
                sizes.push_back(curSize);
                ++k;
            }
            curSize = 0;
        }
    }


    std::cout << k << endl;
    for (auto it: sizes)
    {
        std::cout << it << " ";
    }


    return 0;
}