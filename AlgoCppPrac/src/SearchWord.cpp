#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() < 1) {
            return false;
        }
        bool res = false;
        vector<vector<int>> vis(board.size(), vector<int>(board[0].size(), 0));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    dfs(board, vis, i, j, word, 0, res);
                    if (res) {
                        break;
                    }
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>> const& board, vector<vector<int>>& vis, int i, int j, string word, int index, bool &res) {
        //cout << "dfs on : " << i << " " << j << endl;
        if (index == word.length()) {
            res = true;
            return;
        }
        if (!visited(vis, i, j)) {
            if (board[i][j] == word[index]) {
                for (int k = 0 ; k < 3 ; ++k) {
                    int ni, nj;
                    int trn = 1 << k;
                    if (!(vis[i][j] & trn)) {
                        vis[i][j] |= trn;
                        tuple<int, int> turn = getNextNode(board, i, j, trn);
                        ni = get<0>(turn);
                        nj = get<1>(turn);
                        if (-1 == ni || -1 == nj) {
                            continue;
                        }
                        markTurn(vis, ni, nj, trn);
                        printMat(vis);
                        dfs(board, vis, ni, nj, word, index+1, res);
                    }
                }
            }
            //else {
             //   vis[i][j] |= 2;
            //}
        }
    }

    void markTurn(vector<vector<int>>& v, int i, int j, int turn) {
        switch(turn) {
        case 1:
            v[i][j] |= 2;
            break;
        case 2:
            v[i][j] |= 1;
            break;
        default :
            break;
        }
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
        default:
            return nTurn;
        }
        return (make_tuple(i, j));
    }

    void markLeft(vector<vector<int>> &v, int i, int j) {
        v[i][j] |= 1 << 0;
    }
    void markRight(vector<vector<int>> &v, int i, int j) {
        v[i][j] |= 1 << 1;
    }
    void markDown(vector<vector<int>> &v, int i, int j) {
        v[i][j] |= 1 << 2;
    }

    bool visited(vector<vector<int>> const &v, int i, int j) {
        return (v[i][j] == 0x7);
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
    {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    Solution s;
    s.printMat(board);
    cout << s.exist(board, "ABCCED");

    return 0;
}



