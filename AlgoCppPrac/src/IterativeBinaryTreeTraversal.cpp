#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        stack<TreeNode*> stk;
        stk.push(root);
        root = root->left;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            TreeNode* temp = stk.top();
            res.push_back(temp->val);
            stk.pop();
            root = temp->right;
        }
        //reverseLL(res);
        return res;
    }

    void reverseLL(vector<int>& v) {
        int s = 0;
        while (s < v.size() / 2) {
            int temp = v[s];
            v[s] = v[v.size()-s-1];
            v[v.size()-s-1] = temp;
            s++;
        }
    }

    void printvec(vector<int> v) {
        for (auto a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
};


int main() {
    Solution s;
    TreeNode* root = new TreeNode(1);
    TreeNode* a = new TreeNode(2);
    TreeNode* b = new TreeNode(3);
    TreeNode* c = new TreeNode(4);
    TreeNode* d = new TreeNode(5);
    TreeNode* e = new TreeNode(6);
    TreeNode* f = new TreeNode(7);
    TreeNode* g = new TreeNode(8);
    TreeNode* h = new TreeNode(9);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    b->right = f;
    c->left = g;
    c->right = h;

    vector<int> res = s.inorderTraversal(root);
    s.printvec(res);
    return 0;
}
