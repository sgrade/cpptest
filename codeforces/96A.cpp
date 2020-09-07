// A. Football

#include <iostream>


int main(){

    bool dang = false;

    std::string s;
    getline(std::cin, s);

    int count = 1, maxCount = 1;
    if (s.size()>6){
        int prev = (int)s[0] - 48;
        for (int i=1; i<s.size(); ++i){
            int cur = (int)s[i] - 48;
            if (cur == prev) {
                ++count;
                if (count > maxCount) maxCount = count;
            }
            else count = 1;
            prev = cur;
        }
    }
    
    std::cout << (maxCount> 6 ? "YES\n" : "NO\n");

    return 0;
}