# LeetCode 374 — Guess Number Higher or Lower

## Approaches

1. Standard binary search with `low` and `high` — O(log n) time, O(1) space.
2. Lower-bound style binary search — O(log n) time, O(1) space.
3. Binary search using a `switch` on the guess API result — O(log n) time, O(1) space.

`guess(mid)` returns `0` for correct, `-1` when the guess is too high, and `1` when the guess is too low.
