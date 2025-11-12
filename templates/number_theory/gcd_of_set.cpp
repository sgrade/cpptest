/*
The key mathematical property is the associativity of GCD:
gcd(a, b, c, d, ...) = gcd(gcd(gcd(a, b), c), d), ...)
This means you can compute the GCD of multiple numbers by repeatedly applying
the two-argument GCD function, and the order doesn't matter!
*/

#include <numeric>
#include <unordered_set>

using std::unordered_set;

long long GcdOfSet(const unordered_set<long long>& st) {
  auto it = st.begin();
  long long gcd = *it;
  ++it;
  for (; it != st.end(); ++it) {
    gcd = gcd == 1 ? 1 : std::gcd(gcd, *it);
    if (gcd == 1) {
      break;
    }
  }
  return gcd;
}
