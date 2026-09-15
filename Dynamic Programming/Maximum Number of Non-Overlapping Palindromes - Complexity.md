# Complexity Analysis

Let `n` be the length of the string.

## Time

Expanding around every center takes `O(n^2)` in the worst case.

The prefix DP uses `O(n^2)` candidate transitions in the straightforward formulation, so the overall target remains quadratic.

## Space

The optimized implementation stores only a one-dimensional DP array, using `O(n)` auxiliary space apart from the input string.
