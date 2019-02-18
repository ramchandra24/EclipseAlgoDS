#include <bits/stdc++.h>
using namespace std;

string compressed(string s) {
    string res;
    if (s.length() < 1) {
        return NULL;
    }
    char elem = s[0];
    int cnt = 1;
    for (int i = 1; i < s.length(); ++i) {
        if (elem == s[i]) {
            cnt++;
        }
        else {
            res += elem;
            if (cnt > 1) {
                res += cnt + '0';
            }
            elem = s[i];
            cnt = 1;
        }
    }
    res += elem;
    if (cnt > 1) {
        res += cnt + '0';
    }

    return res;
}

int main() {
    string s = "alasssadsdddd";
    cout << compressed(s) << endl;
    return 0;
}



