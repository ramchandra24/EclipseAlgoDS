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

        ListNode* fir, *sec;
        if (head->next) {
            fir = head->next;
        }
        else {
            return head;
        }
        if (fir->next) {
            sec = fir->next;
        }
        else {
            if (head->val == fir->val) {
                head->next = NULL;
            }
            return head;
        }
        ListNode* curHead = head;
        while (curHead->val == fir->val) {
            curHead = curHead->next;
        }
        head = curHead;
        fir = curHead->next;
        if (fir) {
            sec = fir->next;
        }
        else {
            return head;
        }
        while (sec) {
            if (fir->val == sec->val) {
                fir = sec->next;
                if (fir) {
                    sec = fir->next;
                }
            }
            else {
                head->next = fir;
                head = head->next;
                fir = fir->next;
                sec = sec->next;
            }

#if 0
            if (sec->val != fir->val) {
                if (fir->next == sec) {
                    head->next = fir;
                }
                else {
                    head->next = sec;
                }
                head = head->next;
                //fir = sec;
            }
            fir = sec;
            sec = sec->next;
#endif
        }
        if (fir) {
            head->next = fir;
            head = head->next;
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
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;

    Solution s;
    head = s.deleteDuplicates(head);
    s.printNodes(head);

}
