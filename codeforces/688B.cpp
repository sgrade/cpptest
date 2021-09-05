// B. Lovely Palindromes

#include <iostream>
#include <string>
#include <algorithm>


int main() {

    std::string s;
    std::cin >> s;

    std::cout << s;
    std::reverse(begin(s), end(s));
    std::cout << s << std::endl;

    return 0;
}
