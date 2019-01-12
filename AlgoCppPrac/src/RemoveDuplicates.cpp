#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) {
            return nums.size();
        }
        int cur = 0, newi = 1;
        int twoCount = 0;
        for(int i = 1; i < nums.size(); ++i) {
           if(nums[i] != nums[cur]) {
                swap(nums, ++cur, i);
                twoCount = 0;
           }
           else {
               ++twoCount;
               if (twoCount < 2) {
                   swap(nums, ++cur, i);
               }
           }
        }
        return cur + 1;
    }

    void swap(vector<int>& nums, int i, int j) {
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }

    void printvec(vector<int> a) {
        for (auto v : a) {
            cout << v << " ";
        }
        cout << endl << endl;
    }
};

int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3};
    int len = s.removeDuplicates(nums);
    s.printvec(nums);
    cout << len << endl;
    return 0;
}
