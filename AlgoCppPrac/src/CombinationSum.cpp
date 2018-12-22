#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
#if 0
        vector<vector<int>> m;

        sort(candidates.begin(), candidates.end());
        for (int i = 0; i < candidates.size(); ++i) {
            m.push_back(vector<int>(candidates.size()+1, 0));
        }
        vector<int> row, col;
        col.push_back(0);
        for (int i = 0; i < candidates.size(); ++i) {
            row.push_back(candidates[i]);
            col.push_back(candidates[i]);
        }
        printvec(row);
        printvec(col);


        for (int i = 0; i < m.size(); ++i) {
            for (int j = 1; j < m[i].size(); ++j) {
                m[i][j] = candidates[j-1];
            }
        }

        return m;
        for (int i = 0; i < candidates.size(); ++i) {
            for (int j = 0; j < candidates.size(); ++j) {

            }
        }
#endif
        vector<vector<int>> res;
        vector<int> cvec;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        recursiveTargetSearch(res, candidates, &cvec, sum, 0, target);
        return res;
    }


    void recursiveTargetSearch(vector<vector<int>> &res, vector<int> const& n, vector<int>* c, int sum, int l, int target) {

        for (int i = 0; i < n.size(); ++i) {
            //cout << " I : " << i << " :: " << sum << endl;
            //printvec(*c);
            if (sum + n[i] < target) {
                c->push_back(n[i]);
                sum += n[i];
                recursiveTargetSearch(res, n, c, sum, i, target);
                if (!c->empty()) {
                    //cout << "popping out : " << c->at(c->size() - 1) << endl;
                    sum -= c->at(c->size() - 1);
                    c->pop_back();
                }
            }
            else if (sum + n[i] == target) {
                //cout << "found" << endl;
                sum += n[i];
                c->push_back(n[i]);
                res.push_back(*c);
                c->pop_back();
                //printvec(c);
            }
            //cout << "end of for" << endl;
        }


#if 0




        for (int i = l; i < c.size(); ++i) {
            for (int j = 0; j < c.size(); ++j) {

                while (sum + n[j] < target) {
                    c.push_back(n[j]);
                    sum += n[j];
                }
                if (sum + n[j] == target) {
                    c.push_back(n[j]);
                    res.push_back(c);
                    c.clear();
                    //c.pop_back();
                }
                else {
                    ++j;
                }


                if (sum + n[l] <= target) {
                   c.push_back(n[l]);
                   sum += n[l];
                   if (sum == target) {
                       res.push_back(c);
                   }
                }
                else {
                    return;
                }
                recursiveTargetSearch(res, n, c, sum, i+1, target);
            }
        }
#endif
    }


    void printmat(vector<vector<int>> const& v) {
        cout << endl;
        for (auto a : v) {
            printvec(a);
            cout << endl;
        }
    }

    void printvec(vector<int> const& v) {
        cout << endl;
        for (auto a : v) {
            cout << a << " ";
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    //vector<int> b = {1, 3, 7, 2, 5, 4, 9, 12};
    vector<int> b = {2, 3, 4, 5};
    vector<vector<int>> res = s.combinationSum(b, 8);
    s.printmat(res);
    return 0;
}
