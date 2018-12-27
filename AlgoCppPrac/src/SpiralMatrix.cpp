#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        bool l, r, d;
        for (int i = 0; i <= row / 2; ++i) {
            int col = matrix[i].size();
            l = r = d = false;
            for (int j = i; j < col - i; ++j) {
                res.push_back(matrix[i][j]);
                l = true;
            }
            if (l) {
                for (int j = i + 1; j < row - i; ++j) {
                    res.push_back(matrix[j][col - i - 1]);
                    d = true;
                }
            }
            if (d) {
                for (int j = col - i - 2; j >= i; --j) {
                    res.push_back(matrix[row - i - 1][j]);
                    r = true;
                }
            }

            if (r) {
                for (int j = row - i - 2; j > i ; --j) {
                    res.push_back(matrix[j][i]);
                }
            }
        }
        return res;
    }

    void printmat(vector<vector<int>> m) {
        for (auto a : m) {
            printvec(a);
            cout << endl;
        }
        cout << endl;
    }

    void printvec(vector<int> v) {
        for (auto a : v) {
            cout << a << " ";
        }
        cout << endl;
    }

};

int main() {
    Solution s;
    vector<vector<int>> m = {{1, 2, 3, 4},
            {5, 6, 7, 8},
            {9,10,11,12}};
    vector<int> res = s.spiralOrder(m);
    s.printvec(res);
    return 0;
}
