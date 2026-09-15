# Approach

The solution uses dynamic programming together with palindrome detection by expanding around centers.

For every possible center, expand while the characters match. Whenever the discovered palindrome has length at least `k`, it is a candidate interval.

A one-dimensional DP array stores the best number of palindromes obtainable from each prefix.

This avoids the explicit two-dimensional palindrome table used by the first implementation.
