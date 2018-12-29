#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rsize = matrix.size();
        int csize = 0;
        if (rsize > 0) {
            csize = matrix[0].size();
        }
        int n =   rsize * csize;
        if (n == 0) {
            return false;
        }
        cout << n << endl;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int i = mid / csize;
            int j = mid % csize;
            cout << i << " " << j << " mid " << mid << endl;
            if (target == matrix[i][j]) {
                cout << "found " << i << " " << j << endl;
                return true;
            }
            if (target < matrix[i][j]) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> m =  {
                              {1},
                             };

    Solution s;
    cout << s.searchMatrix(m, 1) << endl;

    return 0;
}
