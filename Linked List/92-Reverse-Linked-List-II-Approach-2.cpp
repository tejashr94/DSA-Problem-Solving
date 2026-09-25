/*
LeetCode 92 - Reverse Linked List II
Approach 2: Standard three-pointer reversal.

1. Locate the node before 'left'.
2. Reverse the sublist using prev/curr/next.
3. Reconnect the reversed segment.

Time: O(n), Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* before = &dummy;

        for (int i = 1; i < left; ++i)
            before = before->next;

        ListNode* curr = before->next;
        ListNode* prev = nullptr;

        for (int i = left; i <= right; ++i) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        ListNode* tail = before->next;
        before->next = prev;
        tail->next = curr;

        return dummy.next;
    }
};
