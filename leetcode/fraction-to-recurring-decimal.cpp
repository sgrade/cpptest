// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <bits/stdc++.h>

using namespace std;


// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        
        string ans;
        
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += '-';
        }
        long num = abs(numerator);
        long denom = abs(denominator);
        
        long x = num / denom;
        ans += to_string(x);
        
        long reminder = num % denom;
        if (reminder == 0) {
            return ans;
        }
        
        ans += '.';
        
        map<int, int> reminders;
        int pos = ans.size() + 1;
        
        while (reminder) {
            reminder *= 10;
            x = reminder / denom;
            reminder = reminder % denom;
            ans += to_string(x);
            if (reminders.find(reminder) != reminders.end()) {
                ans.insert(reminders[reminder], 1, '(');
                ans += ')';
                return ans;
            }
            reminders[reminder] = pos++;
        }
        
        return ans;
    }
};
