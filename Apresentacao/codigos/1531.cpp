#include "bits/stdc++.h"

using namespace std;
using Int = unsigned long long int;

#define _ ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(0);

Int get_pisano_period(Int m) {
    Int a = 0, b = 1, c = a + b;
    for (Int i = 0; i < m * m; i++) {
        c = (a + b) % m; // se a+b == m, entao fib(i)=m.
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 0;
}

// O(logn)
pair < Int, Int > fib(Int n, Int mod) {
    if (n == 0)
        return {0, 1}; // return {fib(n), fib(n+1)}
    pair < Int, Int > p = fib(n / 2, mod); // n/2
    Int first = p.first; // F(n)
    Int second = p.second; // F(n+1)
    Int c = (first * (2 * second - first + mod)) % mod; // F(2n)
    Int d = (first * first) % mod + (second * second) % mod; // F(2n+1)

    if (n & 1) // n is odd: F(n) = F(((n-1) / 2) + 1)^2 + F((n-1) / 2)^2
        return {d % mod, (c + d) % mod};
    else
        return {c % mod, d % mod};
}

pair < Int, Int > fib_helper(Int n, Int mod)
{
  if (n == 0) {
    return {0, 1};
  }

  Int k = 0;
  if (n & 1) {
    k = (n - 1) / 2;
    pair<Int, Int> p = fib_helper(k, mod);
    Int a = p.first;            // F(k) = F((n-1)/2)
    Int b = p.second;            // F(k + 1) = F((n-1)/2 + 1)
    Int c = a * (2 * b - a + mod) % mod; // F(n-1) = F(2k) = F(k) * [2 * F(k + 1) - F(k)]
    Int d = (a * a) % mod + (b * b) % mod;   // F(n) = F(2k + 1) = F(k)^2 + F(k+1)^2
    return {d % mod, (c + d) % mod};
  } else {
    k = n / 2;
    pair<Int, Int> p = fib_helper(k, mod);
    Int a = p.first;            // F(k) = F(n/2)
    Int b = p.second;            // F(k + 1) = F(n/2 + 1)
    return {a * (2 * b - a + mod) % mod, (a * a) % mod + (b * b) % mod};
  }
}

Int fibonacci(Int n, Int m){
		return fib_helper(n,m).first;
}

int main() {
    _
    Int n, m;

    while (cin >> n >> m) {
        Int mod = get_pisano_period(m);
        Int p = fibonacci(n, mod);
        cout << fibonacci(p, m) << endl;
    }

    return 0;
}
