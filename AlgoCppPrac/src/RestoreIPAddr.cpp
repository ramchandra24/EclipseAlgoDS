#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string ip;
        restoreIPAddrUtil(res, s, ip, 0, 0);
        return res;
    }

    void restoreIPAddrUtil(vector<string>& res, string const s, string& ip, int l, int part) {

        //cout << ip << " length : " << l << endl;
        if (l > s.length() || part > 4) {
            return;
        }
        if (part == 4) {
            if (l < s.length()) {
                return;
            }
            //cout << "length : " << ip.length() << endl;
            res.push_back(ip.substr(0, ip.length() - 1));
            return;
        }
        int ipVal;
        if (l < s.length() && validPartIP(s.substr(l,1), part, ipVal)) {
            //cout << ipVal << endl;
            ip += s.substr(l, 1);
            ip += '.';
            restoreIPAddrUtil(res, s, ip, l+1, part+1);
            ip.erase(ip.length() - 2);
        }
        if (l+1 < s.length() && validPartIP(s.substr(l,2), part, ipVal)) {
            ip += s.substr(l, 2);
            ip += '.';
            restoreIPAddrUtil(res, s, ip, l+2, part+1);
            ip.erase(ip.length() - 3);
        }
        if (l+2 < s.length() && validPartIP(s.substr(l,3), part, ipVal)) {
            ip += s.substr(l, 3);
            ip += '.';
            restoreIPAddrUtil(res, s, ip, l+3, part+1);
            ip.erase(ip.length() - 4);
        }
    }

    bool validPartIP(string s, int part, int& res) {
        int ipPart = 0;
        for (int i = 0; i < s.length(); ++i) {
            ipPart = ipPart * 10 + (s[i] - '0');
        }
        res = ipPart;
        if (ipPart > 0 && s[0] == '0') {
            return false;
        }
        else if (ipPart == 0 && s.length() > 1) {
            return false;
        }
        return ((ipPart >= 0) && (ipPart <= 255));
    }

    void printvec(vector<string>& v) {
        cout << "Result" << endl;
        for (string a : v) {
            cout << a << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<string> res = s.restoreIpAddresses("25525511135");
    s.printvec(res);
    return 0;
}
