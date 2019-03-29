#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    struct node* left;
    struct node* right;
    int val;
    node(int v) {
        left = right = NULL;
        val = v;
    }
}Node;

class Solution {
public:
    void printTree(Node* root) {
        if (root == NULL) {
            return;
        }
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
    }

    void flatten(Node* root) {
        while (root) {
            if (root->left && root->right) {
                Node* t = root->left;
                while (t->right) {
                    t = t->right;
                }
                t->right = root->right;
            }
            if (root->left) {
                root->right = root->left;
            }
            root->left = NULL;
            root = root->right;
        }
    }

    void flattenUsingStack(Node* root) {
        stack<Node*> s;
        while (root || !s.empty()) {
            if (root->right) {
                s.push(root->right);
            }
            if (root->left) {
                root->right = root->left;
                root->left = NULL;
            }
            else if (!s.empty()) {
                Node* n = s.top();
                s.pop();
                root->right = n;
            }
            root = root->right;
        }
    }

};

int main() {
    Solution s;
    Node* root = new Node(10);
    Node* a = new Node(8);
    Node* b = new Node(12);
    Node* c = new Node(5);
    Node* d = new Node(9);
    Node* e = new Node(11);
    Node* f = new Node(13);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    cout << endl;
    s.printTree(root);
    s.flattenUsingStack(root);
    cout << endl;
    s.printTree(root);

    return 0;
}
