#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;
        int carry = 0;

        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;

            int sum = a + b + carry;
            carry = sum / 10;

            ListNode* node = new ListNode(sum % 10);

            if (!head) {
                head = tail = node;
            } else {
                tail->next = node;
                tail = node;
            }

            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (carry) tail->next = new ListNode(carry);

        return head;
    }
};