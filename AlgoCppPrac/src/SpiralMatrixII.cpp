#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> rw(n, 0);
        vector<vector<int>> res(n, rw);

        int row = n;
        bool l, r, d;
        unsigned int sq = 0;
        if (row > 0) {
            int times;
            if (row % 2 == 0) {
                times = row / 2;
            }
            else {
                times = row / 2 + 1;
            }
            int col = n;
            for (int i = 0; i < times; ++i) {

                l = r = d = false;
                for (int j = i; j < col - i; ++j) {
                    res[i][j] = ++sq;
                    l = true;
                }
                if (l) {
                    for (int j = i + 1; j < row - i; ++j) {
                        res[j][col - i - 1] = ++sq;
                        d = true;
                    }
                }
                if (d) {
                    for (int j = col - i - 2; j >= i; --j) {
                        res[row - i - 1][j] = ++sq;
                        r = true;
                    }
                }

                if (r) {
                    for (int j = row - i - 2; j > i ; --j) {
                        res[j][i] = ++sq;
                    }
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
    vector<vector<int>> res = s.generateMatrix(3);
    s.printmat(res);
    return 0;
}
