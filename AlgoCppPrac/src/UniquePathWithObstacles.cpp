#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        printGrid(obstacleGrid);
        int m = obstacleGrid.size();
        int mat[100][100] = { {0} };
        for (int i = 0; i < m; ++i) {
            if (obstacleGrid[i][0] == 1) {
                break;
            }
            mat[i][0] = 1;
        }
        int n = obstacleGrid[0].size();
        for (int i = 0; i < n; ++i) {
            if (obstacleGrid[0][i] == 1) {
                break;
            }
            mat[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    mat[i][j] = 0;
                }
                else {
                    mat[i][j] = mat[i-1][j] + mat[i][j-1];
                }
            }
        }

        return mat[m-1][n-1];
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
    vector<vector<int>> obs = { {0,0,0},
            {0,1,0},
            {0,0,0}
    };
    cout << s.uniquePathsWithObstacles(obs) << endl;
    return 0;
}
