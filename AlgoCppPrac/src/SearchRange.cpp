#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2);
        res[0] = binSearchRange(nums, target, true);
        res[1] = binSearchRange(nums, target, false);
        return res;
    }

    int binSearchRange(vector<int> const& nums, int target, bool isLeft) {
        int l = 0;
        int r = nums.size() - 1;
        while ( l <= r ) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                if (isLeft) {
                    if (mid == 0 || nums[mid] != nums[mid - 1]) {
                        return mid;
                    }
                    r = mid;
                }
                else {
                    if (mid == nums.size() -1 || nums[mid] != nums[mid + 1]) {
                        return mid;
                    }
                    l = mid + 1;
                }
                //return mid;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }

    void printvec(vector<int> n) {
        cout << endl;
        for (auto v : n) {
            cout << v << " ";
        }
    }
};


int main() {
    Solution s;
    vector<int> nums = {1, 3, 4, 4, 4, 4, 5, 7, 8, 8, 9, 9, 9, 10, 12, 12};
    vector<int> res = s.searchRange(nums, 5);
    s.printvec(res);
}
