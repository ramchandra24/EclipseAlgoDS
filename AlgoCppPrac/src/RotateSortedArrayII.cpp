#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return searchVec(nums, 0, nums.size() - 1, target);
    }


    bool searchVec(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] < nums[l]) {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            else if (nums[mid] > nums[l]) {
                if (target < nums[mid] && target >= nums[l]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            else {
                ++l;
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << s.search(nums, 0) << endl;
    return 0;
}
