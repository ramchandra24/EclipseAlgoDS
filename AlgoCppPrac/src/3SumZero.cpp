#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int binSearchNum(vector<int> nums, int num, int l, int r) {
        while (l < r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == num) {
                while(num == nums[++mid]);
                return mid-1;
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

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int ans = 0;
        std::map<vector<int>, int> m;
        sort(nums.begin(), nums.end());
        printArr(nums);
        int l = 0, r = nums.size() - 1;
        int origr = r;
        while (l < r-1) {
            int findex = l;
            int f = nums[findex];
            if (f > 0) {
                break;
            }
            cout << endl << "first num: " << f << endl;
            int sindex = binSearchNum(nums, -2*f, findex+1, r);
            if (l >= r) {
                break;
            }
            int s = nums[sindex];
            cout << "second num: " << s << endl;
            int add = f + s;
            int tindex = binSearchNum(nums, -1*add, findex+1, sindex-1);
            int t = nums[tindex];
            if (tindex == findex || tindex == sindex) {
                break;
            }
            cout << "third num: " << t << endl;
            add += t;
            if (add == 0) {
                // found a triplet
                vector<int> arr(3);
                arr[0] = f;
                arr[1] = s;
                arr[2] = t;
                std::map<vector<int>, int>::iterator it;
                it = m.find(arr);
                if (it == m.end()) {
                    res.push_back(arr);
                    m.insert(std::pair<vector<int>, int>(arr, ans));
                    ans++;
                }
                //l++;
                r--;
            }
            else if (add < 0) {
                l++;
                r = origr;
            }
            else {
                r--;
            }
        }
        cout << "done" << endl;
        return res;
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
    vector<int> nums{-4,-1,-4,0,2,-2,-4,-3,2,-3,2,3,3,-4};
    //res = s.threeSum(nums);
    vector<vector<int>> res = s.threeSum(nums);
    s.printVec(res);
}
