#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string res(path.length(), '\0');
        int rlen = 0;
        for (int i = 0; i < path.length(); ++i) {
            switch(path[i]) {
            case '/':
                if (rlen > 0 && res[rlen - 1] == '/') {
                    break;
                }
                res[rlen++] = '/';
                break;
            case '.':
                if (i < path.length() - 2) {
                    if (path[i+1] == '.' && path[i+2] != '/') {
                        while (i < path.length() && path[i] != '/') {
                            res[rlen++] = path[i++];
                            //res[rlen++] = '.';
                        }
                        res[rlen++] = '/';
                    }
                    else if (path[i+1] == '.' && path[i+2] == '/') {
                        res[rlen] = '\0';
                        rlen--; // to remove the last '/'
                        //res[rlen] = '\0';
                        // find the previous '/'
                        while (rlen > 0 && res[rlen - 1] != '/') {
                            res[rlen] = '\0';
                            rlen--;
                        }
                        if (rlen > 0)
                            res[rlen] = '\0';
                        //++i;
                    }
                    else if (path[i+1] == '/') {
                        break;
                    }
                    else {
                        res[rlen++] = path[i];
                    }
                }
                else if (i < path.length() - 1) {
                    if (path[i+1] == '.') {
                        res[rlen] = '\0';
                        rlen--; // to remove the last '/'
                        //res[rlen] = '\0';
                        // find the previous '/'
                        while (rlen > 0 && res[rlen - 1] != '/') {
                            res[rlen] = '\0';
                            rlen--;
                        }
                        if (rlen > 0)
                            res[rlen] = '\0';

                        //++i;
                    }
                    else if (path[i+1] == '/') {
                        break;
                    }
                    else {
                        res[rlen++] = path[i];
                    }
                }
                break;
            default :
                res[rlen++] = path[i];
                break;
            }
            cout << res << " len " << rlen << endl;
        }
        if (rlen > 1 && res[rlen - 1] == '/') {
            res[rlen - 1] = '\0';
        }
        return res;
    }
};

int main() {
    Solution s;
    cout << s.simplifyPath("///..") << endl;
    return 0;
}
