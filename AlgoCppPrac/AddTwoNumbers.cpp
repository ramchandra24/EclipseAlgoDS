/***
 * You are given two non-empty linked lists representing two non-negative
 * integers. The digits are stored in reverse order, and each of their nodes
 * contains a single digit. Add the two numbers and return the sum as a linked
 * list.
 *
 *  * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
        int left_digit = l1 != nullptr ? l1->val : 0;
        int right_digit = l2 != nullptr ? l2->val : 0;
        int sum = left_digit + right_digit + carry;
        int digit = sum % 10;
        carry = sum / 10;
        if (tail == nullptr) {
            head = tail = new ListNode(digit);
        } else {
            tail->next = new ListNode(digit);
            tail = tail->next;
        }
        l1 = l1 != nullptr? l1->next: nullptr;
        l2 = l2 != nullptr? l2->next : nullptr;
    }
    if (carry != 0) {
        // static_assert(tail_node != nullptr);
       tail->next = new ListNode(carry);
    }
    return head;
  }
};