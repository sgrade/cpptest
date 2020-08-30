// A. QAQ

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(){

    string s;
    cin >> s;

    string qaq;
    for (auto it: s) {
        if (it == 'Q' || it == 'A') qaq += it;
    }

    int output = 0;
    // Iterating over A
    //  Got the idea from the editorial - https://codeforces.com/blog/entry/55884
    for (auto it=qaq.begin(); it != qaq.end(); it++)
    {
        if (*it == 'A'){
            int numOfQBefore = count(qaq.begin(), it, 'Q');
            int numOfQAfter = count(it, qaq.end(), 'Q');
            output += numOfQBefore * numOfQAfter;
        }
    }
    
    cout << output << endl;

    return 0;
}