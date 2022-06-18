Source - [https://leetcode.com/problems/divide-two-integers/solution/](https://leetcode.com/problems/divide-two-integers/solution/)


we strongly advise against allowing overflows to happen at all. For some compilers/interpreters/languages, INT_MAX + 1 ≡ INT_MIN. For others, INT_MAX + 1 ≡ INT_MAX. And for others again, it is undefined or crash. Some people on the discussion forum have written code that actually relies on specific overflow behaviour for correctness. While this can be quite "clever", it's not portable at all. For code like that to be shippable, you'd need to be certain of the behaviour of the specific system it is to run on, and that no future system upgrade would change the behaviour. If it works on your machine, but not on Leetcode's machine, it's incorrect code.

In this article, we'll be looking at a few techniques that can solve the problem elegantly and are portable.

In what cases will the final result be out of range?

We're told the following about overflow in the problem description:

For the purpose of this problem, assume that your function returns 2^{31} − 1 when the division result overflows.

So, keeping in mind that our integer range is [−2^{31}, 2^{31} − 1], in what cases could we have an end result outside of this range?

Well, when we do a / b = c, where a and b are both positive integers, we know that c ≤ a. In other words, the answer (c) cannot end up bigger than the thing we divided (the dividend, a).

Something similar happens even when one or both of them are negative. In that case, abs(a) ≤ abs(c). Another way of thinking about it is that c will always be closer to zero than a is (or, they could also be equal).

Therefore, for a and b within the range [−2^{31} + 1, 2^{31} − 1], the result a / b will be closer to zero, so has to be fine.

However, notice we left -2^{31} out of the above range. This is because there's a special case of -2^{31} / -1, which has an answer of 2^{31}. But 2^{31} is outside of the integer range! So instead we return 2^{31}-1 for this case (which is in range).

Most algorithms for this question simply check for the case -2^{31} / -1 at the start, returning 2^{31} - 1 if they detect it. This is a sensible approach.

```cpp
// Special case: overflow.
if (dividend == INT_MIN && divisor == -1) {
    return INT_MAX;
}
```
