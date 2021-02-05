// A. Haiku

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


int main(){

    std::string syl = "aeiou";

    bool ans = true;

    for (int i = 1; i < 4; ++i) {
        std::string line;
        std::getline(std::cin, line);

        int syl_in_line = 0;

        for (auto ch: syl) {
            syl_in_line += count(line.begin(), line.end(), ch);
        }

        if (i == 1 || i == 3) {
            if (syl_in_line != 5) {
                ans = false;
            }
        }
        else if (i == 2) {
            if (syl_in_line != 7) {
                ans = false;
            }
        }
    }

    std::cout << (ans ? "YES" : "NO") << std::endl;

    return 0;
}
