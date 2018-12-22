#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int sz = num1.size() + num2.size();
        vector<int> res(sz, 0);
        num1 = strrev(num1);
        num2 = strrev(num2);
        for (int i = 0; i < num1.size(); ++i) {
            int n1 = num1[i] - '0';
            int carry = 0;
            int j = 0;
            for (; j < num2.size(); ++j) {
                int n2 = num2[j] - '0';
                int m = n1 * n2 + carry;
                carry = m / 10;
                m = m % 10;
                //cout << carry << " " << m << endl;
                res[i + j] += m;
                carry += res[i + j] / 10;
                res [i + j] = res[i + j] % 10;
            }
            if (carry > 0) {
                res[i + j] += carry;
            }
        }
        printvec(res);
        string result;
        for (int it = 0; it < res.size(); ++it) {
            result += res[it] + '0';
        }
        return strrev(result);
    }

    void printvec(vector<int> v) {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }

    string strrev(string s) {
        string res;
        int i = s.size() - 1;
        while (s[i] == '0') {
            --i;
        }
        for (; i >= 0; --i) {
            res += s[i];
        }
        return res;
    }

};


int main() {
    Solution s;

    string res = s.multiply("1002", "110005");
    cout << res << endl;
    return 0;
}
