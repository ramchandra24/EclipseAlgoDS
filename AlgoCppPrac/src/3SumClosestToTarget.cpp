#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binSearchNum(vector<int> nums, int num, int l, int r, bool last) {
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == num) {
                if (last == true) {
                    while(num == nums[++mid]);
                    return mid-1;
                }
                else {
                    return mid;
                }
            }
            if (nums[mid] > num) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return l;
    }

    int threeSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int ans = 0;
        std::map<vector<int>, int> m;
        sort(nums.begin(), nums.end());
        printArr(nums);
        int l = 0, r = nums.size() - 1;
        int sum = INT_MAX;
        int mindiff = INT_MAX;
        for(int i=0; i < nums.size(); ++i) {
            int findex = i;
            int f = nums[findex];
            cout << endl << "first num: " << f << endl;
            int sindex = binSearchNum(nums, -2*f+target, findex+1, r, true);
            if (sindex <= findex) {
                break;
            }
            int tindex = findex + 1;
            while(tindex < sindex) {
                int s = nums[sindex];
                cout << "second num: " << s << endl;
                int t = nums[tindex];
                cout << "third num: " << t << endl;
                int add = f + s + t;
                int diff = abs(target - add);
                if (diff < mindiff) {
                    mindiff = diff;
                    sum = add;
                    cout << "min diff : " << mindiff << endl;
                }
                if (diff == 0) {
                    break;
                }
                else if (add < target) {
                    tindex++;
                }
                else {
                    sindex--;
                }
            }
            if (mindiff == 0) {
                break;
            }
        }
        return sum;
    }

    void printVec(vector<vector<int>>& v) {
        for(unsigned int i=0; i<v.size(); ++i) {
            for(unsigned int j=0; j<v[i].size(); ++j) {
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void printArr(vector<int> v) {
        for(unsigned int i=0; i<v.size(); ++i) {
            cout << v[i] << " ";
        }
        cout << endl;
    }

};


int main() {
    Solution s;
    vector<int> nums{1,1,1,0};
    //res = s.threeSum(nums);
    int res = s.threeSum(nums, 100);
    cout << "res : " << res << endl;
    //s.printVec(res);
}
