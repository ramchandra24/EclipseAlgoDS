#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        set<vector<int>> s;
        vector<int> v;
        vector<int> nums(n);
        for (int i = 1; i <=n; ++i) {
            nums[i-1] = i;
        }
        vector<int> data(k, 0);
        combineRecursive(res, nums, data, 0, 0, k);

        //for (auto it = s.begin(); it != s.end(); ++it) {
         //   res.push_back(*it);
        //}
        return res;
    }

    void combineRecursive(vector<vector<int>>& res, vector<int> const &num, vector<int> &data, int l, int ind, int r) {
        if (l == r) {
            res.push_back(data);
            return ;
        }
        if (ind > num.size() - 1) {
            return ;
        }
        data[l] = num[ind];
        combineRecursive(res, num, data, l+1, ind+1, r);
        combineRecursive(res, num, data, l, ind+1, r);

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
    vector<vector<int>> res = s.combine(5, 3);
    s.printvec(res);
    return 0;
}
