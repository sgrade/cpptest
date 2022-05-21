// https://www.hackerrank.com/challenges/operator-overloading/problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Matrix{
    public:
        Matrix(){};
        vector<vector<int>> a;
        // https://en.cppreference.com/w/cpp/language/operators
        friend Matrix operator+(Matrix& lhs, const Matrix& rhs) {
            for (int i = 0; i < lhs.a.size(); ++i) {
                for (int j = 0; j < lhs.a[i].size(); ++j) {
                    lhs.a[i][j] += rhs.a[i][j];
                }
            }
            return lhs;
        }
    private:
        int n_, m_;
};

int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}
