#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        cout << "rotating" << endl;
        int sz = matrix.size() - 1;
        for (int i = 0; i < sz; ++i) {
            for (int j = i; j < sz - i; ++j) {
                int te = matrix[i][j];
                matrix[i][j] = matrix[sz - j][i];
                matrix[sz - j][i] = matrix[sz - i][sz - j];//matrix[sz - j][sz - i];
                matrix[sz - i][sz - j] = matrix[j][sz - i];//matrix[sz - j][sz - i];
                matrix[j][sz - i] = te;
                //matrix[sz - j][i] = te;
                //= matrix[sz - j][sz - i];

                cout << endl;
                            printvec(matrix);

            }
        }
    }

    void printarr(vector<int> v) {
        for (auto a : v) {
            cout << a << " ";
        }
    }
    void printvec(vector<vector<int>> v) {
        for (auto a : v) {
            printarr(a);
            cout << endl;
        }
    }

};

int main() {
    Solution s;
    vector<vector<int>> image = {
                                 {15,13, 2, 5},
                                 {14, 3, 4, 1},
                                 {12, 6, 8, 9},
                                 {16, 7,10,11}
                                };
    cout << "Initial image" << endl;
    s.printvec(image);

    s.rotate(image);
    cout << endl << "final image " << endl;
    s.printvec(image);
    return 0;
}
