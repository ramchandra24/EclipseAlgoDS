#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less, *more;
        ListNode* curHead = head;
        ListNode* moreHead = NULL;
        less = more = NULL;
#if 0
        if (head) {
            if (head->val < x) {
                less = head;
            }
            else {
                more = head;
            }
            head = head->next;
        }
#endif
        while (head) {
            if (head->val < x) {
                if (less) {
                    less->next = head;
                    less = less->next;
                }
                else {
                    less = head;
                    curHead = head;
                }
            }
            else {
                if (more) {
                    more->next = head;
                    more = more->next;
                }
                else {
                    moreHead = head;
                    more = head;
                }
            }
            head = head->next;
        }
        if (less) {
            less->next = moreHead;
        }
        if (more) {
            more->next = NULL;
        }
        return curHead;
    }

    void printnode(ListNode* head) {
        while (head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }

};

int main() {
    Solution s;
    ListNode* head = new ListNode(1);
    ListNode* a = new ListNode(4);
    ListNode* b= new ListNode(3);
    ListNode* c= new ListNode(2);
    ListNode* d= new ListNode(5);
    ListNode* e= new ListNode(2);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    head = s.partition(head, 3);
    s.printnode(head);

    return 0;
}
