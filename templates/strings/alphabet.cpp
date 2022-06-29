#include <iostream>
#include <string>
#include <unordered_set>

int main() {
  
    std::unordered_set<char> alphabet = {'a','A','b','B','c','C','d','D','e','E','f','F','g','G','h','H','i','I','j','J','k','K','l','L','m','M','n','N','o','O','p','P','q','Q','r','R','s','S','t','T','u','U','v','V','w','W','x','X','y','Y','z','Z'};
    // 26 letters
    std::unordered_set<char> alphabet_low = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    // std::cout << alphabet.size();

    std::unordered_set<char> vowels = {'a','A','e','E','i','I','o','O','u','U'};
    std::string vs = "aeiou";
    
    for (char ch = 'a'; ch <= 'z'; ++ch) {
        std::cout << ch << std::endl;
    }

    return 0;
}
