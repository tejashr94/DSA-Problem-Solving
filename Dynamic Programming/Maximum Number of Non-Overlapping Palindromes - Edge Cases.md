# Edge Cases

1. `k` is larger than the string length: no palindrome can be selected.
2. A string containing no palindrome of length `k`: answer is `0`.
3. All characters are equal: many overlapping palindromes exist, but only non-overlapping intervals count.
4. Multiple palindromes can end at the same position: DP keeps the maximum choice.
5. Single-character palindromes are considered only when `k <= 1`.
