#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (!isRowValid(board) || !isColValid(board)) {
            return false;
        }
        for (int i = 0; i < board.size(); i += 3) {
            for (int j = 0; j < board.size(); j += 3) {
                if (!isBoxValid(board, i, i + 3, j, j + 3)) {
                    return false;
                }
            }
        }
        return true;
    }

    bool isRowValid(vector<vector<char>> const& b) {
        for (auto a : b) {
            unordered_set<char> s;
            for (auto c : a) {
                if (c == '.') {
                    continue;
                }
                if (s.find(c) != s.end()) {
                    return false;
                }
                s.insert(c);
            }
        }
        return true;
    }

    bool isColValid(vector<vector<char>> const& b) {
        vector<unordered_set<char>> s(b.size());
        for (int i = 0; i < b.size(); ++i) {
            for (int j = 0; j < b.size(); ++j) {
                if (b[i][j] == '.') {
                    continue;
                }
                if (s[j].find(b[i][j]) != s[j].end()) {
                    return false;
                }
                s[j].insert(b[i][j]);
            }
        }
        return true;
    }

    bool isBoxValid(vector<vector<char>> const& b, int xi, int xj, int yi, int yj) {
        unordered_set<char> s;
        for (int i = xi; i < xj; ++i) {
            for (int j = yi; j < yj; ++j) {
                if (b[i][j] == '.') {
                    continue;
                }
                if (s.find(b[i][j]) != s.end()) {
                    return false;
                }
                s.insert(b[i][j]);
            }
        }
        return true;
    }
};



int main() {
    Solution s;
    vector<vector<char>> b = {
                    {'5','3','.','.','7','.','.','.','.'},
                    {'6','.','.','1','9','5','.','.','.'},
                    {'.','9','8','.','.','.','.','6','.'},
                    {'8','.','.','.','6','.','.','.','3'},
                    {'4','.','.','8','.','3','.','.','1'},
                    {'7','.','.','.','2','.','.','.','6'},
                    {'.','6','.','.','.','.','2','8','.'},
                    {'.','.','.','4','1','9','.','.','5'},
                    {'.','.','.','.','8','.','.','7','9'}
                             };
    cout << s.isValidSudoku(b) << endl;
    return 0;
}
