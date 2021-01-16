// A. Magic Numbers

#include <iostream>
#include <string>


int main(){

    std::string s;
    getline(std::cin, s);

    bool ans = false;
    int i = 0;

    if (s[i] == '1'){
        ans = true;
        ++i;
        
        while (i < s.size()){
            if (s[i] == '1'){
                ++i;
                continue;
            }
            else if (i > 0 && s[i] == '4' && s[i-1] == '1'){
                ++i;
                continue;
            }
            else if (i > 1 && s[i] == '4' && s[i-2] == '1'){
                ++i;
                continue;
            }
            else {
                ans = false;
                break;
            }
        }

    }

    std::cout << (ans ? "YES" : "NO") << std::endl;

    return 0;
}
