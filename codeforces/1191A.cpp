// A. Tokitsukaze and Enhancement

#include <iostream>

using namespace std;


// <category order, b>
pair<int, char> hp(int x){

   int rem = x % 4;
   
   if (rem == 1) return pair<int, char>(4, 'A');          // A
   else if (rem == 3) return pair<int, char>(3, 'B');     // B
   else if (rem == 2) return pair<int, char>(2, 'C');     // C
   // if (rem == 0)
   else return pair<int, char>(1, 'D');                     // D

}


int main(){

    int x;
    cin >> x;

    int a[3] = {0, 1, 2};

    // <a, b>
    pair<int, char> ans;

    int maxHpCategory = 0;
    for (auto el: a){
        pair<int, char> curPair = hp(x + el);
        if (curPair.first > maxHpCategory){
            maxHpCategory = curPair.first;
            ans = pair<int, char>(el, hp(x + el).second);
        }
    }

    cout << ans.first << ' ' << ans.second << endl;

    return 0;
}
