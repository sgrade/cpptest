// A. Omkar and Password

#include <iostream>
#include <ios>          //used to get stream size
#include <limits>       //used to get numeric limits

using namespace std;


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n;
        scanf("%d\n", &n);

        // output can be only 1 or n
        // 1: if at least two elements are different, we can always find a way to sum them with others
        // n: if all the elements are equal
        int len = 1;

        // if n==1, nothing to do -> result is 1
        if (n==1){
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else {
            bool foundDiff = false;
            int i = n;
            int prev, cur;
            scanf("%d", &prev);
            i--;
            while(i--){
                scanf("%d", &cur);
                if (cur!=prev) {
                    foundDiff = true;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }
                prev = cur;
            }
            if (!foundDiff) {
                len = n;
            }
        }
        
        printf("%d\n", len);

    }

    return 0;
}