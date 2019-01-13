#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return searchVec(nums, 0, nums.size() - 1, target);
    }


    bool searchVec(vector<int>& nums, int l, int r, int target) {
        bool res = false;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            if (nums[mid] < target) {
                if (nums[l] != nums[r]) {
                    // look left
                    if (nums[r] < target) {
                        r = mid - 1;
                    }
                    else {
                        l = mid + 1;
                    }
                }
                else {
                    res |= searchVec(nums, l, mid - 1, target);
                    res |= searchVec(nums, mid + 1, r, target);
                    return res;
                }
            }
            else if (nums[mid] > target) {
# if 0
                if (nums[l] != nums[r]) {
                   // look left
                   if (nums[l] <= target || nums[r] > target) {
                       r = mid - 1;
                   }
                   else {
                       l = mid + 1;
                   }
               }
# endif
         //      else {
                   res |= searchVec(nums, l, mid - 1, target);
                   res |= searchVec(nums, mid + 1, r, target);
                   return res;
       //        }
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
