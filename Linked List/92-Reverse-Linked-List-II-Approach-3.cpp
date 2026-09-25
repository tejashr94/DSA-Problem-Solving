/*
LeetCode 92 - Reverse Linked List II
Approach 3: Recursive reversal of exactly the required range.

The helper reverses the first k nodes and returns the new head.
The successor is attached to the old head of the reversed part.

Time: O(n), Space: O(n) due to recursion.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    ListNode* successor = nullptr;

    ListNode* reverseK(ListNode* head, int k) {
        if (k == 1) {
            successor = head->next;
            return head;
        }

        ListNode* newHead = reverseK(head->next, k - 1);
        head->next->next = head;
        head->next = successor;
        return newHead;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        if (left == 1)
            return reverseK(head, right);

        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
};
