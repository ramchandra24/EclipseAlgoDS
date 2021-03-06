#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 1;
        while (i > 0 && nums[i] <= nums[i-1]) {
            --i;
        }
        if (i > 0 && nums[i] > nums[i-1]) {
            int j = i+1;
            int max = i;
            while (j < nums.size()) {
                if ((nums[j] < nums[max]) && (nums[j] > nums[i-1])) {
                    max = j;
                }
                ++j;
            }
            swapnums(nums, max, i-1);
            sort(nums.begin() + i, nums.end());
        }
        else {
            sort(nums.begin(), nums.end());
        }
    }

    void swapnums(vector<int>& n, int i, int j) {
        auto v = n[i];
        n[i] = n[j];
        n[j] = v;
    }

    void printvec(vector<int> const& n) {
        cout << endl;
        for (auto i : n) {
            cout << i << " ";
        }
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 2, 2};
    s.printvec(nums);
    s.nextPermutation(nums);
    s.printvec(nums);
    return 0;
}
