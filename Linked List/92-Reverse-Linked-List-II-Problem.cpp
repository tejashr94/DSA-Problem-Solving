/*
LeetCode 92 - Reverse Linked List II

Problem:
Given the head of a singly linked list and integers left and right,
reverse the nodes from position left to right and return the list.

Approach 1:
In-place head insertion with a dummy node.
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
            ListNode* move = curr->next;
            curr->next = move->next;
            move->next = prev->next;
            prev->next = move;
        }

        return dummy.next;
    }
};
