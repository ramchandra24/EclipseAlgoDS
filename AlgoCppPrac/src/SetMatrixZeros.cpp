#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bitset<1000> rb, cb;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    cb[j] = 1;
                    rb[i] = 1;
                }
            }
        }
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (rb[i] == 1 && cb[j] == 1) {
                    fillRowColZero(matrix, i, j);
                }
            }
        }
    }

    void fillRowColZero(vector<vector<int>>& m, int r, int c) {
        cout << r << " " << c << endl;
        for (int i = 0; i < m.size(); ++i) {
            m[i][c] = 0;
        }
        for (int i = 0; i < m[0].size(); ++i) {
            m[r][i] = 0;
        }
    }

    void printMat(vector<vector<int>> const& mat) {
        cout << endl;
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
    vector<vector<int>> m = { {0,1,2,0},{3,4,5,2},{1,3,1,5} };
    s.printMat(m);
    s.setZeroes(m);
    s.printMat(m);
    return 0;
}
