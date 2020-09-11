// A. Olesya and Rodion

#include <iostream>
#include <string>

int main(){

    int n, t;
    scanf("%d %d", &n, &t);

    std::string output;

    // e.g. 1, 10; 2, 100
    if (n < std::to_string(t).size()){
        output = "-1";
    }

    else{
        output += std::to_string(t);
        while(output.size() < n){
            output += '0';
        }
    }
  

    std::cout << output << std::endl;

    return 0;
}