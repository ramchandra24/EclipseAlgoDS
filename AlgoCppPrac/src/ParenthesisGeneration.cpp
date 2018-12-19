#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<string> permute(string s) {
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            //cout << endl;
            //cout << s;
            if (checkValid(s) == true) {
                res.push_back(s);
            }
        } while(next_permutation(s.begin(), s.end()));
        return res;
    }

    bool checkValid(string s) {
        stack<char> st;
        for(auto const& c : s) {
            if (c == ')') {
                if (st.empty()) {
                    return false;
                }
                st.pop();
            }
            else if (c == '('){
                st.push(c);
            }
        }
        if (st.empty()) {
            return true;
        }
        return false;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        for(auto i = 0; i < n; ++i) {
            s += '(';
        }
        for(auto i = 0; i < n; ++i) {
                    s += ')';
        }
        res = permute(s);
        return res;
    }
    void printresult(vector<string> v) {
        cout << endl;
        for(auto const& r : v) {
            cout << r << endl;
        }
    }
};

int main() {
    Solution s;
    vector<string> res = s.generateParenthesis(3);
    cout << endl << "result " << endl;
    s.printresult(res);
    return 0;
}
