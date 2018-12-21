#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int last = nums.size() - 1;
        int res = -1;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                // decreasing part
                if (nums[mid] < nums[0]) {
                    if (target > nums[0]) {
                       r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                if (nums[mid] > nums[last]) {
                    if (target < nums[last]) {
                       l = mid + 1;
                    }
                    else {
                        r = mid - 1;
                    }
                }
                else {
                        r = mid - 1;
                }
            }
        }
        if (l == r) {
            return l;
        }
        return res;
    }
};

int main() {

    Solution s;
    vector<int> nums = {10, 11, 12, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << s.search(nums, 13) << endl;

    return 0;
}
