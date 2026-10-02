# LeetCode 88 — Merge Sorted Array

## Approaches

1. **Two pointers from the end** — O(m + n) time, O(1) extra space.
2. **Reverse merge with a single remaining-count loop** — O(m + n) time, O(1) extra space.
3. **Insert + sort** — O((m + n) log(m + n)) time.

The first two approaches preserve the required in-place merge behavior without extra arrays.
