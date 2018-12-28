#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> mat(grid.size(), vector<int> (grid[0].size(), 0));
        int rsum = 0;
        for (int i = 0; i < mat.size(); ++i) {
            mat[i][0] = rsum + grid[i][0];
            rsum = mat[i][0];
        }
        int csum = 0;
        for (int i = 0; i < mat[0].size(); ++i) {
            mat[0][i] = csum + grid[0][i];
            csum = mat[0][i];
        }

        for (int i = 1; i < mat.size(); ++i) {
            for (int j = 1; j < mat[i].size(); ++j) {
                mat[i][j] = grid[i][j] + min(mat[i-1][j], mat[i][j-1]);
            }
        }
        printGrid(mat);
        return mat[mat.size() - 1][mat[0].size() - 1];
    }

    int min(int a, int b) {
        int ret = a < b ? a : b;
        return ret;
    }

    void printmat(int mat[][100], int m, int n) {
       for (int i = 0; i < m; ++i) {
           for (int j = 0; j < n; ++j) {
               cout << mat[i][j] << " ";
           }
           cout << endl;
       }
       cout << endl;
   }

    void printGrid(vector<vector<int>> const& mat) {
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[i].size(); ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

};

int main() {
    Solution s;
    vector<vector<int>> grid = { {1,3,1},
            {1,5,1},
            {4,2,1} };
    s.printGrid(grid);
    cout << s.minPathSum(grid) << endl;
    return 0;
}
