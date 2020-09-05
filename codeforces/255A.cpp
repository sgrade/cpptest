// A. Greg's Workout

#include <iostream>
#include <map>
#include <string>


int main(){

    int n;
    scanf("%d\n", &n);

    int tmp, iter=1;
    std::map<std::string,int> m;
    for (int i=0; i<n; ++i)
    {
        scanf("%d", &tmp);
        switch(iter){
            case 1:
                m["chest"] += tmp;
                iter = 2;
                break;
            case 2:
                m["biceps"] += tmp;
                iter = 3;
                break;
            case 3:
                m["back"] += tmp;
                iter = 1;
                break;
        }
    }

    std::string output;
    int prevMax=0;
    for (auto it: m){
        if(it.second > prevMax){
            output = it.first;
            prevMax = it.second;
        }
    }

    std::cout << output << std::endl;

    return 0;
}
