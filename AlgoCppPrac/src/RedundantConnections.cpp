#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        vector<set<int>> s;
        bool end[2];
        for (auto e : edges) {
            end[0] = true;
            end[1] = true;
            auto v1 = e[0];
            auto v2 = e[1];
            vector<set<int>>::iterator sv[2];
            for (int i = 0; i < 2; ++i) {
                for (vector<set<int>>::iterator st = s.begin(); st != s.end(); ++st) {
                    if ((*st).find(e[i]) != (*st).end()) {
                            sv[i] = st;
                            end[i] = false;
                            break;
                    }
                }
            }
            if (end[0]) {
                set<int> st0 {e[0]};
                s.push_back(st0);
                sv[0] = s.end() - 1;
            }
            if (end[1]) {
                set<int> st1{e[1]};
                s.push_back(st1);
                sv[1] = s.end() - 1;
            }

            if ( (!end[0]) && (!end[1]) && (0 == distance(sv[0], sv[1])) ) {
                vector<int> res;
                res.push_back(e[0]);
                res.push_back(e[1]);
                return res;
            }
            else {
                //(*sv[0]).insert((*sv[1]).begin(), (*sv[1]).end());
                set<int> tset;
                printsetelems(*sv[0]);
                printsetelems(*sv[1]);
                tset.insert((*sv[0]).begin(), (*sv[0]).end());
                tset.insert((*sv[1]).begin(), (*sv[1]).end());
                printsetelems(tset);
                //merge((*sv[0]).begin(), (*sv[0]).end(), (*sv[1]).begin(), (*sv[1]).end(), tset.begin());
                 cout << "inside" <<endl;
                printset(s);
                s.erase(sv[0]);
                s.erase(sv[1]);
                s.push_back(tset);
            }
            printset(s);

#if 0
            else if ( (!end[0]) && (!end[1]) && (0 != distance(sv[0], sv[1])) ) {
                set<int> iset;
                // Merge the two sets and remove the original set from vector
                iset.insert(*sv[0]);
                iset.insert(*sv[1]);
                s.push_back(iset);
                // Remove original set
                s.erase(sv[0]);
                s.erase(sv[1]);
            }
            else {
                set<int> iset;
                iset.insert(e[0]);
                iset.insert(e[1]);
                s.push_back(iset);
            }
#endif
        }
        vector<int> res;
        res.push_back(-1);
        res.push_back(-1);
        return res;
    }

    void printset(vector<set<int>>& v) {
        cout << "Set" << endl;
        for (auto a : v) {
            for (auto it = a.begin(); it != a.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    void printarr(vector<vector<int>> const& v) {
        for (auto a : v) {
            //cout << a << " : ";
            printarr(v);
        }
        cout << endl;
    }

    void printsetelems(set<int> const& v) {
        cout << "Set elements : ";
        for (auto it = v.begin(); it != v.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

};


int main() {

    Solution s;
    vector<vector<int>> ed = {{3, 4}, {1, 2}, {2, 4}, {3, 5}, {2, 5}};
    vector<int> res = s.findRedundantConnection(ed);
    //s.printarr(res);

    return 0;
}

