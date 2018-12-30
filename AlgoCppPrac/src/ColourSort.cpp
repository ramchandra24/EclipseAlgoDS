#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int ze = 0, tw = nums.size() - 1, on = ze;
        while ( on <= tw ) {
            if (nums[ze] == 0) {
                ++ze;
            }
            else if (nums[tw] == 2) {
                --tw;
            }
            else {
                if (on > ze && nums[on] == 0) {
                    swap(nums, ze, on);
                    ++ze;
                }
                else if (nums[on] == 2) {
                    swap(nums, tw, on);
                    --tw;
                }
                else {
                    ++on;
                }
            }
        }

    }

    void swap(vector<int> & n, int i, int j) {
        int t = n[i];
        n[i] = n[j];
        n[j] = t;
    }

    void printarr(vector<int> const& n) {
        for (auto a : n) {
            cout << a << " ";
        }
        cout << endl;
    }

};

int main() {
    vector<int> n = {2, 1};
    Solution s;
    s.sortColors(n);
    s.printarr(n);
    return 0;
}
