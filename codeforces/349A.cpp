// A. Cinema Line

#include <stdio.h>
#include <map>


int main(){

    int n;
    scanf("%d\n", &n);

    std::map <int, int> mp = {
        {25, 0},
        {50, 0},
        {100, 0}
    };

    bool changeNegative = false;

    int tmp;
    for (int i=0; i<n; ++i){
        scanf("%d", &tmp);
        switch (tmp){
            case 25:
                ++mp[25];
                break;
            case 50:
                ++mp[50];
                break;
            case 100:
                ++mp[100];
                break;
        }

        // giving change
        while(tmp>25 && !changeNegative){
            if (tmp == 75){
                if (mp[50] > 0) {
                    --mp[50];
                    tmp -= 50;
                }
            }
            if (tmp>25){
                --mp[25];
                tmp -= 25;
            }
            for (auto it: mp){
                if (it.second < 0){
                    changeNegative = true;
                    break;
                }
            }
        }        
    }

    printf("%s\n", (changeNegative ? "NO" : "YES"));

    return 0;
}