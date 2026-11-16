// LeetCode 2: Add Two Numbers
// Approach: Digit-by-digit addition with carry
// Time: O(max(m, n)), Space: O(max(m, n)) for the result

#include <bits/stdc++.h>
using namespace std;

// LeetCode provides this definition:
// struct ListNode { int val; ListNode *next; ListNode() : val(0), next(nullptr) {}
// ListNode(int x) : val(x), next(nullptr) {}
// ListNode(int x, ListNode *next) : val(x), next(next) {} };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }
        return dummy.next;
    }
};
