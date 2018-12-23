#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) != m.end()) {
                m[s].push_back(strs[i]);
            }
            else {
                vector<string> v(1, strs[i]);
                m.insert(make_pair(s, v));
            }
        }
        printmap(m);
        vector<vector<string>> res;
        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            res.push_back(it->second);
        }
        return res;

    }

    void printmap(map<string, vector<string>> & m) {
        for (map<string, vector<string>>::iterator it = m.begin(); it != m.end(); ++it) {
            printarr(it->second);
            //cout << it->first << endl;
        }
    }

    void printarr(vector<string> const& s) {
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    void printvec(vector<vector<string>> const& v) {
        for (int i = 0; i < v.size(); ++i) {
            printarr(v[i]);
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<string> st = {"eat", "tea", "tan", "ate", "nat", "bat"};
    s.printarr(st);
    vector<vector<string>> res = s.groupAnagrams(st);
    s.printvec(res);

    return 0;
}
