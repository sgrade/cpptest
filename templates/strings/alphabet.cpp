#include <iostream>
#include <string>


int main() {

    // 26 letters
    
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; 

    for (char ch = 'a'; ch <= 'z'; ++ch) {
        std::cout << ch << std::endl;
    }

    return 0;
}
