#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() < 1) {
            return false;
        }
        bool res = false;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    vector<vector<bool>> vis(board.size(), vector<bool>(board[0].size(), false));
                    res = dfs(board, vis, i, j, word, 0);
                    if (res) {
                        break;
                    }
                }
            }
            if (res) {
                break;
            }
        }
        return res;
    }

    bool dfs(vector<vector<char>> const& board, vector<vector<bool>>& vis, int i, int j, string word, int index) {
        //cout << "dfs on : " << i << " " << j << endl;
        vis[i][j] = true;
        bool res = false;

        if (index >= word.length()-1) {
            if (board[i][j] == word[index]) {
                return true;
            }
        }
        else {
            if (board[i][j] == word[index]) {
                printMat(vis);
                for (int k = 0 ; k < 4 ; ++k) {
                    int ni, nj;
                    int trn = 1 << k;
                    tuple<int, int> turn = getNextNode(board, i, j, trn);
                    ni = get<0>(turn);
                    nj = get<1>(turn);
                    if (-1 == ni || -1 == nj) {
                        continue;
                    }
                    if (!vis[ni][nj]) {
                        res |= dfs(board, vis, ni, nj, word, index+1);
                        if (res) {
                            return res;
                        }
                        vis[ni][nj] = false;
                        //return res;
                    }
                }
            }
        }
        return res;
    }

    tuple<int, int> getNextNode(vector<vector<char>> const& board, int i, int j, int turn) {
        tuple<int, int> nTurn(-1, -1);
        switch(turn) {
        case 1:
            --j;
            if (j < 0) {
                return nTurn;
            }
            break;
        case 2:
            ++j;
            if (j >= board[i].size()) {
                return nTurn;
            }
            break;
        case 4:
            ++i;
            if (i >= board.size()) {
                return nTurn;
            }
            break;
        case 8:
            --i;
            if (i < 0) {
                return nTurn;
            }
            break;
        default:
            return nTurn;
        }
        return (make_tuple(i, j));
    }

    template <typename T>
    void printMat(vector<vector<T>> const &v) {
        for (auto a : v) {
            for (auto c : a) {
                cout << c << " " ;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {

    vector<vector<char>> board =
    /*{
            {'A','B','C','E'},
            {'S','F','E','S'},
            {'A','D','E','E'}
    };*/
    {
            {'A','B','C','E'}, {'S','F','E','S'}, {'A','D','E','E'}
    };
    Solution s;
    s.printMat(board);
    cout << s.exist(board, "ABC");

    return 0;
}



