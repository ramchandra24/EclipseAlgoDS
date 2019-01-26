#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nCr(int n, int r) {
        int** com = new int* [n+1];
        for (int i = 0; i <= n; ++i) {
            com[i] = new int[r+1];
        }
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= r; ++j) {
                com[i][j] = 0;
            }
        }

        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= min(i, r); ++j) {
                if (i == 0 || j == 0) {
                    com[i][j] = 1;
                }
                else {
                    com[i][j] = com[i-1][j] + com[i-1][j-1];
                }
            }
        }
        return com[n][r];
    }
};

int main() {
    Solution s;
    cout << s.nCr(15, 3) << endl;
    return 0;
}
