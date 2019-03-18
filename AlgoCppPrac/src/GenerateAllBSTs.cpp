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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;//(n);
        res = generateTreesUtil(1, n);

        return res;
    }

    vector<TreeNode*> generateTreesUtil(int start, int end) {
        vector<TreeNode*> trees;
        if (start > end) {
            trees.push_back(NULL);
            //return trees;
        }
        else if (start == end) {
            TreeNode* t = new TreeNode(start);
            trees.push_back(t);
        }
        else {
            for (int i = start; i <= end; ++i) {
                vector<TreeNode*> left = generateTreesUtil(start, i-1);
                vector<TreeNode*> right = generateTreesUtil(i+1, end);
                for (int k = 0; k < left.size(); ++k) {
                    for (int j = 0; j < right.size(); ++j) {
                        TreeNode* root = new TreeNode(i);
                        root->left = left[k];
                        root->right = right[j];
                        trees.push_back(root);
                    }
                }
            }
        }
        return trees;
    }

    void printTrees(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        printTrees(root->left);
        cout << root->val << " ";
        printTrees(root->right);
    }
};


int main() {
    Solution s;
    vector<TreeNode*> res = s.generateTrees(3);
    for (auto a : res) {
        s.printTrees(a);
        cout << endl;
    }
    return 0;
}
