#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for (int i = 0; i <= nums.size(); ++i) {
            vector<int> data(i);
            combineRecursive(res, data, nums, 0, 0, i);
        }

        return res;
    }

    void combineRecursive(vector<vector<int>> &res, vector<int> &data, vector<int> const& num, int l, int index, int r) {
        if (l == r) {
            res.push_back(data);
            return;
        }
        if (index > num.size() - 1) {
            return;
        }
        data[l] = num[index];
        combineRecursive(res, data, num, l+1, index+1, r);
        combineRecursive(res, data, num, l, index+1, r);
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
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<vector<int>> res = s.subsets(nums);
    s.printvec(res);

    return 0;
}
