// 937. Reorder Data in Log Files
// https://leetcode.com/problems/reorder-data-in-log-files/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        int n = logs.size();
        
        vector<vector<string>> let, dig;
        
        for (string &s: logs) {
            
            vector<string> tmp(2);
            size_t pos = s.find(' ');
            tmp[0] = s.substr(0, pos);
            tmp[1] = s.substr(pos+1);
            
            if (isalpha(tmp[1][0])) {
                let.push_back(tmp);
            }
            else {
                dig.push_back(tmp);
            }
            
        }
        
        sort(let.begin(), let.end(), [](const vector<string>& v1, const vector<string>& v2){
            if (v1[1] == v2[1]) return v1[0] < v2[0];
            return v1[1] < v2[1];
        });
        
        vector<string>output(n);
        int i;
        for (i = 0; i < let.size(); ++i) {
            output[i] = let[i][0] + ' ' + let[i][1];
        }
        int j;
        for (; i < n; ++i) {
            j = i - let.size();
            output[i] = dig[j][0] + ' ' + dig[j][1];
        }
        
        return output;
    }
};


int main() {

    vector<string> logs = {"a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"};
    
    Solution sol;

    for (string& s: sol.reorderLogFiles(logs)) {
        cout << s << "\n";
    }

    return 0;
}
