// 3337. Total Characters in String After Transformations II
// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/

#include <bits/stdc++.h>

using namespace std;


// Based on Editorial's Approach: Matrix Multiplication + Matrix Exponentiation By Squaring
const int LETTERS = 26, MOD = 1e9 + 7;

class Matrix {
public:
    Matrix() { memset(a, 0, sizeof(a)); }
    Matrix (const Matrix& m) {
        for (int i = 0; i < LETTERS; ++i) {
            for (int j = 0; j < LETTERS; ++j) {
                a[i][j] = m.a[i][j];
            }
        }
    }

    Matrix& operator = (const Matrix& m) {
        if (this != &m) {
            for (int i = 0; i < LETTERS; ++i) {
                for (int j = 0; j < LETTERS; ++j)
                    a[i][j] = m.a[i][j];
            }
        }
        return *this;
    }

    int a[LETTERS][LETTERS];
};

Matrix operator * (const Matrix& m1, const Matrix& m2) {
    Matrix ans;
    for (int i = 0; i < LETTERS; ++i) {
        for (int j = 0; j < LETTERS; ++j) {
            for (int k = 0; k < LETTERS; ++k)
                ans.a[i][j] = (ans.a[i][j] + (long long)m1.a[i][k] * m2.a[k][j]) % MOD;
        }
    }
    return ans;
}

Matrix IdentityMatrix () {
    Matrix m;
    for (int i = 0; i < LETTERS; ++i)
        m.a[i][i] = 1;
    return m;
}

// Exponentiation by squaring
Matrix MatrixExponentiation (const Matrix& matrix, int power) {
    Matrix ans = IdentityMatrix(), m = matrix;
    while (power) {
        if (power & 1)
            ans = ans * m;
        m = m * m;
        power >>= 1;
    }
    return ans;
}


class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        Matrix m;
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j)
                m.a[(i + j) % 26][i] = 1;
        }

        Matrix r = MatrixExponentiation (m, t);
        int ans = 0;
        vector<int> counter(26);
        for (const char& ch: s)
            ++counter[ch - 'a'];
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j)
                ans = (ans + (long long)r.a[i][j] * counter[j]) % MOD;
        }
        return ans;
    }
};
