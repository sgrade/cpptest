// A. Ilya and Bank Account

#include <iostream>
#include <string>


int main(){

    int n;
    std::cin >> n;

    int output;
    if (n>=0) output = n;

    else {
        std::string s1 = std::to_string(n);
        std::string s2 = std::to_string(n);

        std::string lastRemoved = s1.erase(s1.size()-1, 1);
        std::string beforeLastRemoved = s2.erase(s2.size()-2, 1);

        output = std::max(std::stoi(lastRemoved), std::stoi(beforeLastRemoved));
    }

    std::cout << output << std::endl;

    return 0;
}