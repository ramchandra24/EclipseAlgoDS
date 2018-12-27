#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int toJump = nums.size() - 1;
        int i = toJump - 1;
        bool res = true;
        while (i >= 0) {
            if (nums[i] >= (toJump - i)) {
                toJump = i;
                res = true;
            }
            else {
                res = false;
            }
            --i;
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = {3, 0};
    cout << s.canJump(nums);
    return 0;
}
