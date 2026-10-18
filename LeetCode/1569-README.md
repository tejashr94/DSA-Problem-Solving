# LeetCode 1569 — Number of Ways to Reorder Array to Get Same BST

Count reorderings that create the same BST as the given array, excluding the original ordering.

## Core recurrence

For a sequence of size \(n\), the first value is the root. Split remaining values into left and right subsequences. If the left side has \(L\) values, the left and right sequences can be interleaved in \(\binom{n-1}{L}\) ways while preserving relative order inside each side.

\[
ways(nums) = \binom{n-1}{L} \cdot ways(left) \cdot ways(right)
\]

The final answer is \((ways(nums)-1+MOD)\bmod MOD\).

## Approaches

1. **Pascal triangle + recursion** — precomputes all binomial coefficients in a 2D table. See [Approach 1](1569-Number-of-Ways-to-Reorder-Array-to-Get-Same-BST.cpp).
2. **Factorials + modular inverse** — computes \(\binom{n}{k}=fact[n]\cdot invFact[k]\cdot invFact[n-k]\pmod{MOD}\). See [Approach 2](1569-Approach-2-Factorial-Inverse.cpp).
3. **Memoized recursive subproblems** — stores computed results by sequence in a map, together with Pascal-triangle combinations. This demonstrates memoization, though map/vector key copying adds overhead. See [Approach 3](1569-Approach-3-Memoized-Recursion.cpp).

## Complexity

- Approaches 1 and 2: typically \(O(n^2)\) time and \(O(n^2)\) space due to repeated partitioning and temporary vectors (factorial tables themselves use \(O(n)\) space in Approach 2).
- Approach 3: extra memoization and vector-key comparison/copying overhead means its constants and worst-case complexity are higher; it is mainly for illustrating memoization.
- Modulus: \(10^9+7\).

## Example

Input: `[2,1,3]`  
Valid reorderings: `[2,1,3]`, `[2,3,1]`  
Exclude the original ordering, so output is `1`.
