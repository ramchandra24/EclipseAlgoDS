#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, pri = 0;
        while (i < (nums.size() - 1)) {
            pri = i;
            i += nums[i];
            if (i >= (nums.size() - 1)) {
                return true;
            }
            if (nums[i] == 0) {
                int start = i;
                int end = start;
                while (end < nums.size() && nums[end] == 0) {
                    ++end;
                }
                int jump;
                if (end == nums.size()) {
                    // special case. just jump to the end.
                    jump = end - start;
                }
                else {
                    jump = end - start + 1;
                }

                int j;
                for (j = pri; j < start; ++j) {
                    if (nums[j] >= jump + start - j) {
                        i = j + jump + start;
                        break;
                    }
                }
                if (j == start) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> nums = {2, 5, 0, 0};
    cout << s.canJump(nums);
    return 0;
}
