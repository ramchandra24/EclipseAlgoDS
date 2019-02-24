#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        int count = 1;
        while (temp && count++ < m) {
            prev = temp;
            temp = temp->next;
        }
        if (count < m) {
            return head;
        }
        if (prev == NULL) {
            head = reverseLL(temp, (n-m));
        }
        else {
            prev->next = reverseLL(temp, (n-m));
        }

        return head;
    }

    ListNode* reverseLL(ListNode* head, int count) {
        if (head == NULL) {
            return head;
        }
        ListNode* prev = head;
        ListNode* cur = head->next;
        while (cur && count-- > 0) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head->next = cur;
        return prev;
    }

    ListNode* recursiveReverse(ListNode* head, int const m, int& depth) {
        if (head->next == NULL || head->next->next == NULL || m == depth) {
             return head;
        }
        depth++;
        //head = head->next;
        head->next->next = recursiveReverse(head->next, m, depth);
        return head;
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
    ListNode* c = new ListNode(4);
    ListNode* d = new ListNode(5);

    head->next = a;
    a->next = b;
    //b->next = c;
    c->next = d;

    Solution s;
    head = s.reverseBetween(head, 1, 5);
    s.printNodes(head);

    return 0;
}
