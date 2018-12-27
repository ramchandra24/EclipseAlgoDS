#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        char ar[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        string s;
        for (auto i = 0; i < n; ++i) {
            s += ar[i];
        }
        while (k > 1) {
            next_permutation(s.begin(), s.end());
            --k;
        }
        return s;
    }
};

int main() {

    Solution s;
    string res = s.getPermutation(5, 120);
    cout << res << endl;
    return 0;
}
