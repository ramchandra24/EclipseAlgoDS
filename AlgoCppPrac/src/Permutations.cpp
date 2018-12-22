#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> v;
        permuteRecursive(s, nums, 0);

        for (auto it = s.begin(); it != s.end(); ++it) {
            res.push_back(*it);
        }
        return res;
    }

    void permuteRecursive(set<vector<int>>& res, vector<int> &num, int l) {
        if (l == num.size()) {
            res.insert(num);
            return ;
        }
        for (int i = l; i < num.size(); ++i) {
            swap(num, i, l);
            permuteRecursive(res, num, l+1);
            swap(num, i, l);
        }
    }

    void swap(vector<int>& n, int i, int j) {
        int te = n[i];
        n[i] = n[j];
        n[j] = te;
    }

    void printvec(vector<vector<int>> const &v) {
        for (auto a : v) {
            for (auto c : a) {
                cout << c << " " ;
            }
            cout << endl;
        }
    }
};

int main() {
    Solution s;
    vector<int> v = {1, 2, 3};
    vector<vector<int>> res = s.permute(v);
    s.printvec(res);
    return 0;
}
