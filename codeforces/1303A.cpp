// A. Erasing Zeroes

#include <iostream>
#include <string>

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while(t--){
        string s;
        getline(cin, s);

        int zToRem = 0, consequitiveZ = 0;
        for (unsigned i=1; i < s.size(); ++i){
            int sIminusOne = s[i-1] - 48;
            int sI = s[i] - 48;
            if (sIminusOne==1 && sI==0){
                consequitiveZ ++;
            }
            else if (sIminusOne==0 && sI==0){
                if (consequitiveZ > 0) consequitiveZ++;
            }
            else if (sIminusOne==0 && sI==1){
                if (consequitiveZ > 0) zToRem += consequitiveZ;
                consequitiveZ = 0;
            }
        }

        cout << zToRem << endl;
    }

    return 0;
}