#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> lets = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        stack<string> st1, st2, rest;

        auto ldigs = digits[digits.length() - 1];
        int ldig = ldigs - '0';
        for(auto& c : lets[ldig - 2]) {
            res.push_back(string(1, c));
        }

        vector<string> cp;
        for (auto i = 0; i < digits.length() - 1; ++i) {
            auto num = digits[digits.length() - i - 2];
            auto n = stoi(string(1, num));
            auto app = lets[n-2];

            cp.clear();
            for (auto const& s : res) {
                cp.push_back(s);
            }
            res.clear();
            //cout << app << endl;
            for(auto& c : app) {
                for(auto const& s : cp) {
                    res.push_back(c + s);
                }
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
    cout << "starting " << endl;
    vector<string> vs = s.letterCombinations("234");
    cout << "end" << endl;
    s.printVec(vs);
    return 0;
}


