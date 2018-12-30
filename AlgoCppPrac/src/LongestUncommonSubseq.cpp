#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if (a.length() == 0 && b.length() == 0) {
            return -1;
        }
        int len = a.length() < b.length()? a.length(): b.length();
        int llen = a.length() > b.length()? a.length(): b.length();
        if (len == 0) {
            return llen;
        }
        if (llen > len) {
            return llen;
        }
        bool flag = false;
        for (int i = 0; i < len; ++i) {
            if (a[i] != b[i]) {
                flag = true;
            }
        }
        if (!flag) {
            return -1;
        }
        return llen;
    }
};

int main() {
    string a = "asdkjfoihwe";
    string b = "aswherknsadf";
    Solution s;
    cout << s.findLUSlength(a, b) << endl;
    return 0;
}
