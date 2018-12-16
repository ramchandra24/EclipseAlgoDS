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

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int ans = 0;
        std::map<vector<int>, int> m;
        sort(nums.begin(), nums.end());
        printArr(nums);
        int l = 0, r = nums.size() - 1;
        for(int i=0; i < nums.size(); ++i) {
            int findex = i;
            int f = nums[findex];
            cout << endl << "first num: " << f << endl;
            if (f > 0) {
                break;
            }
            int sindex = binSearchNum(nums, -2*f, findex+1, r, true);
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
                if (add == 0) {
                    // found a triplet
                    vector<int> arr(3);
                    arr[0] = f;
                    arr[1] = s;
                    arr[2] = t;
                    sort(arr.begin(), arr.end());
                    std::map<vector<int>, int>::iterator it;
                    it = m.find(arr);
                    if (it == m.end()) {
                        res.push_back(arr);
                        m.insert(std::pair<vector<int>, int>(arr, ans));
                        ans++;
                    }
                    sindex--;
                }
                else if (add < 0) {
                    tindex++;
                }
                else {
                    sindex--;
                }
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
    vector<int> nums{-2, -1, -1, 0,0,0, 2, 1, 3, 2};
    //res = s.threeSum(nums);
    vector<vector<int>> res = s.threeSum(nums);
    s.printVec(res);
}
