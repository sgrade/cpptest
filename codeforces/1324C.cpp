// C. Frog Jumps

#include <iostream>
#include <string>


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){

        std::string s;
        std::getline(std::cin>>std::ws, s);

        int curL=0, maxL=0;
        for (int i=0; i<s.size(); ++i){
            if (s[i] == 'L'){
                ++curL;
                if (curL > maxL){
                    maxL = curL;
                }
            }
            else {
                curL = 0;
            }
        }

        std::cout << maxL+1 << std::endl;

    }

    return 0;
}