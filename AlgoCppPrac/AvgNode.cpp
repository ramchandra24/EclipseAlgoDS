#include <bits/stdc++.h>

using namespace std;

typedef struct node {
    int value;
    vector<struct node* >child;
}Node;


class Solution {
public:
    void getnode(Node* root, double& min, Node* &res) {
        if (root->child.size() > 0) {
            double avg = INT_MIN;
            avg = (double)getsum(root) / getsize(root);
            cout << "avg : " << (double)avg << " :: a : " << root->value << endl;
            if (avg > min) {
                min = avg;
                res = root;
            }
                for (auto a : root->child) {
                getnode(a, min, res);
            }
        }
    }

    int getsize(Node* root) {
        if (root->child.size() == 0) {
            return 1;
        }
        else {
            int s = 1;
            for (auto v : root->child) {
                s += getsize(v);
            }
            return s;
        }
    }

    int getsum(Node* root) {
        if (root->child.size() == 0) {
            return root->value;
        }
        else {
            int s = root->value;
            for (auto v : root->child) {
                s += getsum(v);
            }
            return s;
        }
    }

};


int main() {
    Node* root = new Node();
    root->value = 1;
    Node* a = new Node();
    a->value = 2;
    root->child.push_back(a);
    Node* b = new Node();
    b->value = 3;
    a->child.push_back(b);

    Solution s;
    double m = (double)(s.getsum(root) / s.getsize(root));
    cout << "root avg : " << m << endl;
    Node* res = root;
    s.getnode(root, m, res);

    cout << res->value << endl;
}
