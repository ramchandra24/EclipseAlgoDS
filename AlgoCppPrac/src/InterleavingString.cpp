#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    
    bool is_interleave_int(string s1, size_t i, string s2, size_t j, string s3, size_t k) {
        if (k == s3.length()) {
            // We created the resultant string. Verify if both strings were used up completely.
            return i == s1.length() && j == s2.length();
        }
        if (i < s1.length() && s1[i] == s3[k]) {
            bool res = is_interleave_int(s1, i+1, s2, j, s3, k+1);
            // Only when we haven't found the char in first string, check the second.
            if (res) return true;
        }
        if (j < s2.length() && s2[j] == s3[k]) {
            return is_interleave_int(s1, i, s2, j+1, s3, k+1);
        }
        return false;
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.length() != s1.length() + s2.length()) return false;
        return is_interleave_int(s1, 0, s2, 0, s3, 0); 
    }
};

int main() {
    Solution s;
    bool result = s.isInterleave("bbbbbabbbbabaababaaaabbababbaaabbabbaaabaaaaababbbababbbbbabbbbababbabaabababbbaabababababbbaaababaa", "babaaaabbababbbabbbbaabaabbaabbbbaabaaabaababaaaabaaabbaaabaaaabaabaabbbbbbbbbbbabaaabbababbabbabaab", "babbbabbbaaabbababbbbababaabbabaabaaabbbbabbbaaabbbaaaaabbbbaabbaaabababbaaaaaabababbababaababbababbbababbbbaaaabaabbabbaaaaabbabbaaaabbbaabaaabaababaababbaaabbbbbabbbbaabbabaabbbbabaaabbababbabbabbab");
    return result;
}