#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> res;
        vector<int> cvec;
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        recursiveTargetSearch(res, candidates, &cvec, sum, 0, target);

        vector<vector<int>> result;
        for (auto it = res.begin(); it != res.end(); ++it) {
            result.push_back(*it);
        }

        return result;
    }


    void recursiveTargetSearch(set<vector<int>> &res, vector<int> const& n, vector<int>* c, int sum, int l, int target) {

        for (int i = l; i < n.size(); ++i) {
            //cout << " I : " << i << " :: " << sum << endl;
            //printvec(*c);
            if (sum + n[i] < target) {
                c->push_back(n[i]);
                sum += n[i];
                recursiveTargetSearch(res, n, c, sum, i+1, target);
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
                vector<int> cpy(*c);
                sort(cpy.begin(), cpy.end());
                res.insert(cpy);
                //res.push_back(*c);
                c->pop_back();
                //printvec(c);
            }
            //cout << "end of for" << endl;
        }
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
    vector<int> b = {1, 3, 4, 5, 8};
    vector<vector<int>> res = s.combinationSum2(b, 8);
    s.printmat(res);
    return 0;
}



