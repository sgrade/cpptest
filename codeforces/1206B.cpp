// B. Make Product Equal One

#include <iostream>

using namespace std;


int main(){

    int n;
    cin >> n;

    long long ans = 0, negatives = 0, zeros = 0;

    int tmp;
    while(n--){
        cin >> tmp;
        if(tmp < 0){
            ++negatives;
            if(tmp < -1) ans += -1 - tmp;
        }
        else if(tmp > 1){
            ans += tmp - 1;
        }
        else if(tmp == 0){
            ++zeros;
            ++ans;
        }
    }

    if(negatives % 2 != 0 && zeros == 0) ans += 2;

    cout << ans << endl;

    return 0;
}
