# 

#include <stdio.h>
#include <vector>
#include <algorithm>


std::vector<unsigned long long> fibNumbers(unsigned long long n){
    std::vector<unsigned long long> f = {0};
    if (n == 0) return f;
    f.push_back(1);
    for (unsigned long long i = 2; i < n + 1; ++i){
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return f;
}


int main(){

    int n;
    scanf("%d\n", &n);
    std::vector<unsigned long long> fNums = fibNumbers(n + 1);
    std::vector<char> output;
    for (int i = 1; i < n + 1; ++i){
        auto found = std::find(fNums.begin(), fNums.end(), i);
        if (found != fNums.end()){
            printf("%c", 'O');
        }
        else printf("%c", 'o');
    }
    printf("\n");
    return 0;   
}
