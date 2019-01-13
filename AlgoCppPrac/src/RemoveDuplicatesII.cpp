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

        ListNode* cur;
        if (head->next) {
            cur = head->next;
        }
        else {
            return head;
        }
        ListNode* curHead = head;
        while (cur) {
            if (cur->val != head->val) {
                head->next = cur;
                head = head->next;
            }
            cur = cur->next;
        }
        if (head->next) {
            head->next = NULL;
        }
        return curHead;
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
    ListNode* a = new ListNode(2);
    ListNode* b = new ListNode(3);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(4);
    ListNode* f = new ListNode(5);

    head->next = a;
    //a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    Solution s;
    head = s.deleteDuplicates(head);
    s.printNodes(head);

}
