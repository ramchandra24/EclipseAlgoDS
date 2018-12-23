#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double r = x;
        double f = x;
        double num = x;
        int inc = 1, dec = 1;
        int po = 1;
        while (po != n) {
            if (po > n) {
                num /= f;
                f *= f;
                dec += dec;
                po -= dec / 2;
                inc = 1;
                r = x;
            }
            else {
                num *= r;
                r *= r;
                inc += inc;
                po += inc / 2;
                dec = 1;
                f = x;
            }
        }
        return num;
    }
};

int main() {
    Solution s;
    cout << s.myPow(2.1, -3) << endl;
    return 0;
}
