#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int *dp = new int[s.length() + 1];
        for (int i = 0; i <= s.length(); ++i) {
            dp[i] = 0;
        }
        if (s.length() == 0 || s == "") {
            return 0;
        }
        dp[0] = 1;
        dp[1] = s[0] == '0' ? 0 : 1;
        for (int i = 2; i <= s.length(); ++i) {
            if (s[i-1] != '0') {
                dp[i] += dp[i-1];
            }
            if (((s[i-2] - '0') * 10 + (s[i-1] - '0')) >= 10 &&
                    ((s[i-2] - '0') * 10 + (s[i-1] - '0')) <= 26) {
                dp[i] += dp[i-2];
            }
        }
        int ans = dp[s.length()];
        delete[] dp;
        return ans;
    }
};

int main() {

    Solution s;
    cout << s.numDecodings("12") << endl;
    return 0;
}



