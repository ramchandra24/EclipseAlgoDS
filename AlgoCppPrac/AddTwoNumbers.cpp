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
    ListNode* result = nullptr;
    ListNode* tail_node = nullptr;
    while (l1 != nullptr || l2 != nullptr) {
        int left = l1 != nullptr ? l1->val : 0;
        int right = l2 != nullptr ? l2->val : 0;
        int sum = left + right + carry;
        int next_number = sum % 10;
        carry = sum / 10;
        if (result == nullptr) {
            result = tail_node = new ListNode(next_number);
        } else {
            // static_assert(tail_node != nullptr);
            tail_node->next = new ListNode(next_number);
        }
        l1 = l1 != nullptr? l1->next: nullptr;
        l2 = l2 != nullptr? l2->next : nullptr;
        if (tail_node->next != nullptr) {
            tail_node = tail_node->next;
        }
    }
    if (carry != 0) {
        // static_assert(tail_node != nullptr);
       tail_node->next = new ListNode(carry);
    }
    return result;
  }
};