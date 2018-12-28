#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int mat[100][100] = { {0} };
        for (int i = 0; i < m; ++i) {
            mat[i][0] = 1;
        }
        for (int i = 0; i < n; ++i) {
            mat[0][i] = 1;
        }
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                mat[i][j] = mat[i-1][j] + mat[i][j-1];
            }
        }
        printmat(mat, m, n);
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
};

int main() {
    Solution s;
    cout << s.uniquePaths(3, 7) << endl;
    return 0;
}
