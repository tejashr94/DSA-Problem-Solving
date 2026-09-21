#include <bits/stdc++.h>
using namespace std;

class Solution {
    void addLists(ListNode*& head, ListNode*& tail, ListNode* a, ListNode* b, int& carry) {
        int sum = (a ? a->val : 0) + (b ? b->val : 0) + carry;
        carry = sum / 10;

        ListNode* node = new ListNode(sum % 10);

        if (!head) head = tail = node;
        else {
            tail->next = node;
            tail = node;
        }
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 || l2) {
            addLists(head, tail, l1, l2, carry);

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry) addLists(head, tail, nullptr, nullptr, carry);

        return head;
    }
};