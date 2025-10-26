// 2043. Simple Bank System
// https://leetcode.com/problems/simple-bank-system/

#include <vector>

using std::vector;


class Bank {
public:
    Bank(vector<long long>& balance) {
        this->n = balance.size();
        this->balance.insert(this->balance.end(), balance.begin(), balance.end());
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (account1 > n || account2 > n || balance[account1] < money) {
            return false;
        }
        balance[account1] -= money;
        balance[account2] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if (account > n) {
            return false;
        }
        balance[account] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if (account > n || balance[account] < money) {
            return false;
        }
        balance[account] -= money;
        return true;
    }

private:
    int n;
    vector<long long> balance = {0};
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
