source - [https://leetcode.com/problems/string-to-integer-atoi/solution/](https://leetcode.com/problems/string-to-integer-atoi/solution/)
```cpp
// Check overflow and underflow conditions. 
int sign;
if (digit > 0) sign = 1;
else if (digit < 0) sign = -1;
// !!! treat case digit == 0 separately if required !!!
if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) { 
    // If integer overflowed return 2^31-1, otherwise if underflowed return -2^31.    
    return sign == 1 ? INT_MAX : INT_MIN;
}
```