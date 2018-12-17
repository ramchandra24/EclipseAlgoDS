#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lets = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        stack<string> st1, st2;

        auto ldigs = digits[digits.length() - 1];
        int ldig = ldigs - '0';
        for(auto& c : lets[ldig - 2]) {
            st1.push(string(1, c));
        }

        bool s1 = true, s2 = false;
        for(auto i = 0; i < digits.length() - 1; ++i) {
            auto num = digits[digits.length() - i - 2];
            auto n = stoi(string(1, num));
            auto app = lets[n-2];
            //cout << app << endl;
            for(auto& c : app) {
                if (s1 == true) {
                    string str = st1.top();
                    st1.pop();
                    st2.push(c + str);
                    if (st1.empty()) {
                        s1 = false;
                        s2 = true;
                    }
                }
                else if (s2 == true) {
                        string str = st2.top();
                        st2.pop();
                        st1.push(c + str);
                        if (st2.empty()) {
                            s1 = true;
                            s2 = false;
                        }
                }
            }
        }
        if (st1.empty()) {
            while (!st2.empty()) {
                auto st = st2.top();
                res.push_back(st);
                st2.pop();
            }
        }
        else if (st2.empty()) {
            while (!st1.empty()) {
                auto st = st1.top();
                res.push_back(st);
                st1.pop();
            }
        }
        return res;
    }

    void printVec(vector<string> v) {
        for(auto elem : v) {
            cout << elem << endl;
        }
    }

};

int main() {
    Solution s;
    vector<string> vs = s.letterCombinations("234");
    s.printVec(vs);
    return 0;
}


