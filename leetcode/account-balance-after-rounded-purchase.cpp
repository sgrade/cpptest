// 2806. Account Balance After Rounded Purchase
// https://leetcode.com/problems/account-balance-after-rounded-purchase/

#include bits/stdc++.h>

using namespace std;


class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int rem = purchaseAmount % 10;
        if (rem < 5)
            return 100 - purchaseAmount + rem;
        else
            return 100 - purchaseAmount - 10 + rem;
    }
};
