#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int val;
    struct node* left;
    struct node* right;
}Node;

typedef struct lnode {
    int val;
    struct lnode* next;
}LNode;

class Solution {
public :
    Node* newNode(int val) {
        Node* n = new Node;
        n->val = val;
        n->left = n->right = NULL;
        return n;
    }

    LNode* newLNode(int val) {
        LNode* n = new LNode;
        n->val = val;
        n->next = NULL;
        return n;
    }

    int countLNodes(LNode* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    Node* BSTfromLL(LNode* head) {
        int count = countLNodes(head);
        Node* root = NULL;
        __BSTfromLL(&root, &head, count);
        return root;
    }

    Node* __BSTfromLL(Node** root, LNode** head, int count) {
        if (count <= 0) {
            return NULL;
        }
        *root = newNode(0);
        (*root)->left = __BSTfromLL(&(*root)->left, head, count / 2);
        (*root)->val = (*head)->val;
        *head = (*head)->next;
        (*root)->right = __BSTfromLL(&(*root)->right, head, count - count / 2 - 1);
        return *root;
    }

    void printLNodes(LNode* head) {
        while (head) {
            cout << head->val << " ";
        }
        cout << endl;
    }

    void printNodes(Node* root) {
        if (root == NULL) {
            return;
        }
        printNodes(root->left);
        cout << root->val << " ";
        printNodes(root->right);
    }
};

int main() {
    Solution s;
    LNode* head = s.newLNode(1);
    LNode* a = s.newLNode(2);
    LNode* b = s.newLNode(3);
    LNode* c = s.newLNode(4);
    LNode* d = s.newLNode(5);
    LNode* e = s.newLNode(6);

    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Node* root = s.BSTfromLL(head);
    s.printNodes(root);

    return 0;
}
