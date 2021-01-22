// C. Yet Another Array Restoration

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> check (int n, int x, int y, int diff){
    int candidate = y - diff;
    vector<int> output = {x, y};
    while (candidate > 0 && output.size() < n){
        if (candidate != x) output.push_back(candidate);
        candidate -= diff;
    }

    candidate = y + diff;
    while (output.size() < n){
        output.push_back(candidate);
        candidate += diff;
    }

    sort(output.begin(), output.end());

    return output;
}


int main(){

    int t;
    scanf("%d\n", &t);

    while (t--){

        int n, x, y;
        scanf("%d %d %d\n", &n, &x, &y);

        vector<int> output = {x, y};

        if (n > 2){
            int diff = y - x;
            output = check(n, x, y, diff);

            --diff;
            while (diff >= ((y - x) + (n - 1) - 1) / (n - 1)){
                if ((y - x) % diff == 0) {
                    vector<int> tmp = check(n, x, y, diff);
                    if (tmp[n-1] < output[n-1] ){
                        output = tmp;
                    }
                }
                --diff;
            }


        }
        
        for (auto el: output) cout << el << ' ';
        cout << endl;
    }

    return 0;
}
