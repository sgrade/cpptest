// C. Need for Pink Slips
// Wrong answer on test 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;


vector<double> cmp(3);
double v;
double ans;
vector<long long> cntr(2, 1);

void check(int i, double cur_ans, long long cnt) {

    while (true) {
        cur_ans *= cmp[i];
        cmp[2] += v / 2;
        ++cnt;
        if (cmp[i] <= v) {
            break;
        }
        else {
            cmp[i] -= v;
        }
    }

    // to be used later in CCCMMMP cases 
    cmp[i] = cur_ans;
    cntr[i] = cnt;

    cur_ans *= cmp[2];
    cur_ans *= cnt;

    ans += cur_ans;
}


int main() {

    int t;
    cin >> t;

    while (t--) {

        cin >> cmp[0] >> cmp[1] >> cmp[2] >> v;

        double cur_ans;

        // P
        ans = cmp[2];

        // CP, MP
        cntr[0] = 1;
        cntr[1] = 1;
        for (int i = 0; i < 2; ++i) {
            check(i, 1, 1);
        }
        
        // CCCMMMP
        int j;
        for (int i = 0; i < 2; ++i) {
            j = i == 0 ? 1 : 0;
            check(i, cmp[j], cntr[j]);
        }

        cout << setprecision(std::numeric_limits<long double>::digits10 + 1) << ans << endl;
    }

    return 0;
}
