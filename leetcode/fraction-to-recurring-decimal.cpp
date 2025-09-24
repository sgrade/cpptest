// 166. Fraction to Recurring Decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;
using std::to_string;


// Based on Editorial's Fraction to Recurring Decimal
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }

        string fraction;

        // One of the numbers is negative
        if (numerator < 0 ^ denominator < 0) {
            fraction += '-';
        }

        long long num = labs(1LL * numerator), denom = labs(1LL * denominator);
        fraction += to_string(num / denom);
        
        long long reminder = num % denom;
        if (reminder == 0) {
            return fraction;
        }
        fraction += '.';
        unordered_map<long long, int> counter;
        while (reminder != 0) {
            if (counter.count(reminder)) {
                fraction.insert(counter[reminder], "(");
                fraction += ')';
                break;
            }
            counter[reminder] = fraction.size();
            reminder *= 10;
            fraction += to_string(reminder / denom);
            reminder %= denom;
        }

        return fraction;
    }
};
