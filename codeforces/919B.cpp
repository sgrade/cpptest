// B. Perfect Number

#include <stdio.h>
#include <string>


int main(){

    int k;
    scanf("%d", &k);

    int kCount = 0;
    std::string s;
    for (int i=19; kCount<10001; i+=9){
        s = std::to_string(i);
        int sum = 0;
        for (int j=0; j<s.size(); ++j){
            sum += (int)s[j]-48;
        }
        if (sum == 10){
            ++kCount;
            if (kCount == k) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
