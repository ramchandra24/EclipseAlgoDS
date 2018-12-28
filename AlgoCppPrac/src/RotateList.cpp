#include <bits/stdc++.h>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *kLast = head;
        ListNode *ktemp = head;
        if (head == NULL) {
            return head;
        }
        for (int i = 0; i < k; ++i) {
            ktemp = ktemp->next;
            if (ktemp == NULL) {
                ktemp = head;
            }
        }
        while (ktemp->next) {
            kLast = kLast->next;
            ktemp = ktemp->next;
        }
        ListNode *newHead;
        if (kLast->next) {
            newHead = kLast->next;
            ktemp->next = head;
        }
        else {
            newHead = head;
        }
        kLast->next = NULL;

        return newHead;
    }

    void printList(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};


int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    ListNode *a = new ListNode(2);
    ListNode *b = new ListNode(3);
    ListNode *c = new ListNode(4);
    ListNode *d = new ListNode(5);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;

    s.printList(head);

    ListNode* rotList = s.rotateRight(head, 6);
    s.printList(rotList);

    return 0;
}
