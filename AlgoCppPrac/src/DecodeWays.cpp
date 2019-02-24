#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        char a[26];
        for (int i = 0; i < 26; ++i) {
            a[i] = 'A' + i;
        }
        string test = "";
        set<string> res;
        decodeUtil(res, a, s, test, 0);
        printRes(res);
        return res.size();
    }

    void printRes(set<string> s) {
        for (auto v : s) {
            cout << v << endl;
        }
    }

    void decodeUtil(set<string>& res, char const a[26], string s, string test, int l) {

        if (l >= s.length()) {
            string cp (test);
            sort(cp.begin(), cp.end());
            res.insert(cp);
            //ans = res.size();
            return;
        }

        for (int i = l; i < s.length(); ++i) {
            test += a[s[i] - '0' - 1];
            cout << "before test " << test << endl;
            decodeUtil(res, a, s, test, i + 1);
            test.erase(test.length() - 1);
            cout << "after test " << test << endl;
            if (i < s.length() - 1) {
                int v = (s[i] - '0') * 10 + (s[i + 1] - '0') - 1;
                test += a[v];
                decodeUtil(res, a, s, test, i + 2);
                test.erase(test.length() - 1);
            }
        }
    }

};

int main() {

    Solution s;
    s.numDecodings("226");
    return 0;
}



