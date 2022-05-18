// A. Marks

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main() {

    int n, m;
    cin >> n >> m;

    vector<string> a(n);

    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> successful_students(n);

    int ans = 0;

    int mx_grade;

    for (int j = 0; j < m; ++j) {

        mx_grade = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i][j] > mx_grade) {
                mx_grade = a[i][j];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (a[i][j] == mx_grade) {
                successful_students[i] = 1;
            }
        }
    }

    ans = count(successful_students.begin(), successful_students.end(), 1);

    cout << ans << '\n';

    return 0;
}
