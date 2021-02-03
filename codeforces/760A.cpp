// A. Petr and a calendar

#include <iostream>
#include <vector>

using namespace std;


int main(){

    vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int m, d;
    cin >> m >> d;
    --m;

    int columns = 1;
    months[m] -= 8 - d;

    columns += months[m] / 7;
    months[m] -= 7 * (columns - 1);

    if (months[m] > 0) {
        columns += 1;
    }

    cout << columns << endl;

    return 0;
}
