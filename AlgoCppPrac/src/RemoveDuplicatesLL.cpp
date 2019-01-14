#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode* cur = head->next;
        int v = head->val;
        if (v != cur->val) {
            head->next = deleteDuplicates(cur);
            return head;
        }
        else {
            while (cur && v == cur->val) {
                cur = cur->next;
            }
            return deleteDuplicates(cur);
        }
    }

    void printNodes(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

};


int main() {
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(1);
    ListNode* c = new ListNode(2);
    ListNode* d = new ListNode(3);
    ListNode* e = new ListNode(2);
    ListNode* f = new ListNode(2);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    //d->next = e;
    e->next = f;

    Solution s;
    head = s.deleteDuplicates(head);
    s.printNodes(head);

}
