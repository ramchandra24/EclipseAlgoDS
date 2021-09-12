#include <string>
#include <iostream>

class Solution {
public:
    std::string group_and_count_nums(std::string str_num) {
        // This function should group the numbers, count consecutive digits and // return a string representing the resulting number.
        int freq = 1;
        std::string result = "";
        int prev_digit = str_num[0] - '0';
        int curr_digit = -1;
        int str_len = str_num.length();
        for (int i = 1; i < str_len; ++i) {
            curr_digit = str_num[i] - '0';
            if (curr_digit == prev_digit) {
                ++freq;
            }
            else {
                result += std::to_string(freq * 10 + prev_digit);
                prev_digit = curr_digit;
                freq = 1;
            }
        }
        result +=  std::to_string(freq * 10 + prev_digit);
        return result;
    }
    
    std::string countAndSay(int n) {
        // We only need the previous result to get current result.
        std::string prev_res = "1";
        std::string curr_res = prev_res;
        for (int i = 2; i <= n; ++i) {
            curr_res = group_and_count_nums(prev_res);
            prev_res = curr_res;
        }
        return curr_res;
    }
};

int main() {
    Solution s;
    std::cout << s.countAndSay(7);
    return 0;
}