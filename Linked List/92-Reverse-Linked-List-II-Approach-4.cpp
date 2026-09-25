/*
LeetCode 92 - Reverse Linked List II
Approach 4: Repeatedly move the next node to the front of the sublist.

This is another in-place technique. The node after curr is extracted and
inserted immediately after prev until the required range is reversed.

Time: O(n), Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0, head);
        ListNode* prev = &dummy;

        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode* curr = prev->next;

        for (int i = 0; i < right - left; ++i) {
            ListNode* next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
