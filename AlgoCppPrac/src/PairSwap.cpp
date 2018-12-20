#include <bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* nxt, *nnxt, *tail;
        ListNode* nhead = head;
        tail = NULL;
        if ((!head) || (!head->next)) {
            return head;
        }

        nhead = swappair(head);
        tail = head;
        head = head->next;

        while (head) {
            tail->next = swappair(head);
            tail = head;
            head = head->next;
        }

        return nhead;
    }

    ListNode* swappair(ListNode* head) {
        ListNode* nxt = NULL;
        ListNode* nnxt = NULL;
        if (!head) {
            return head;
        }

        if (head->next) {
            nxt = head->next;
            nnxt = nxt->next;
            nxt->next = head;
        }
        head->next = nnxt;
        if (nxt) {
            return nxt;
        }
        return head;
    }

    void printlist(ListNode* head) {
        cout << endl;
        while (head) {
            cout << head->val << " " ;
            head = head->next;
        }
        cout << endl;
    }
};

int main() {
    ListNode l1 = ListNode(10);
    ListNode l2 = ListNode(20);
    ListNode l3 = ListNode(30);
    ListNode l4 = ListNode(40);
    ListNode l5 = ListNode(50);
    ListNode l6 = ListNode(60);
    ListNode l7 = ListNode(70);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    //l4.next = &l5;
    //l5.next = &l6;
    //l6.next = &l7;

    Solution s;
    ListNode* head = s.swapPairs(&l1);
    s.printlist(head);
    return 0;
}
