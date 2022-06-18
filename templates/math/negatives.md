Source - [https://leetcode.com/problems/divide-two-integers/solution/](https://leetcode.com/problems/divide-two-integers/solution/)


Assuming that both the dividend and divisor are positive, here is a code snippet for this process.

```cpp
public int divide(int dividend, int divisor) {
    int quotient = 0;
    while (dividend - divisor >= 0) {
        quotient++;
        dividend -= divisor;
    }
    return quotient;
}
```

This doesn't work if one, or both, of the `dividend` or `divisor` are negative—the dividend will head away from zero! Trying to generalise this code to handle all four of the possible sign combinations is problematic, because some are repeated addition instead of subtraction, and some have `a <= 0` continuation case instead of `>= 0`.

A logical solution here is to simply convert any negative inputs to positives, and then put a negative sign back on at the end if needed. Recall that `positive * negative = negative`, and `negative * negative = positive`. In other words, if there was exactly one negative sign in the inputs, the final result is negative. Otherwise, it's positive.

```cpp
/* We need to convert both numbers to negatives.
 * Also, we count the number of negatives signs. */
int negatives = 2;
if (dividend > 0) {
    negatives--;
    dividend = -dividend;
}
if (divisor > 0) {
    negatives--;
    divisor = -divisor;
}
/* If there was originally one negative sign, then
 * the quotient remains negative. Otherwise, switch
 * it to positive. */
if (negatives != 1) {
    quotient = -quotient;
}
```
