#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
  bool is_interleave_int_dp(string s1, string s2, string s3) {
    // Start bottom-up. Mark arr[i][j] as true iff s3(0, i+j) can be formed
    // using s1(0, i) and s2(0, j).
    int m = s1.length();
    int n = s2.length();
    if (s3.length() != (m + n))
      return false;
    bool arr[m + 1][n + 1];
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        arr[i][j] = false;
      }
    }
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        if (i == 0 && j == 0) {
          arr[i][j] = true;
          continue;
        }
        if (i == 0) {
          arr[0][j] = (s2[j - 1] == s3[j - 1]) ? arr[0][j - 1] : false;
        } else if (j == 0) {
          arr[i][0] = (s1[i - 1] == s3[i - 1]) ? arr[i - 1][0] : false;
        } else {
          char curr_ch = s3[i + j - 1];
          if (curr_ch == s1[i - 1] && curr_ch != s2[j - 1]) {
            arr[i][j] = arr[i - 1][j];
          } else if (curr_ch != s1[i - 1] && curr_ch == s2[j - 1]) {
            arr[i][j] = arr[i][j - 1];
          } else if (curr_ch == s1[i - 1] && curr_ch == s2[j - 1]) {
            arr[i][j] = arr[i][j - 1] | arr[i - 1][j];
          }
        }
      }
    }
    return arr[m][n];
  }

    bool is_interleave_int(string s1, size_t i, string s2, size_t j, string s3, size_t k) {
        if (k == s3.length()) {
            // We created the resultant string. Verify if both strings were used up completely.
            return i == s1.length() && j == s2.length();
        }
        if (i < s1.length() && s1[i] == s3[k]) {
            bool res = is_interleave_int(s1, i+1, s2, j, s3, k+1);
            // Only when we haven't found the char in first string, check second.
            if (res) return true;
        }
        if (j < s2.length() && s2[j] == s3[k]) {
            return is_interleave_int(s1, i, s2, j+1, s3, k+1);
        }
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        // return is_interleave_int(s1, 0, s2, 0, s3, 0); 
        return is_interleave_int_dp(s1, s2, s3);
    }
};

int main() {
    Solution s;
    // bool result = s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    bool result = s.isInterleave("aabcc",
"dbbca",
"aadbbcbcac");
    cout << result;
    return result;
}