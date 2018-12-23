#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        double p = myPow(x, n / 2);
        if (n % 2 == 0) {
            return p * p;
        }
        else {
            if (n > 0) {
                return (x*p*p);
            }
            else {
                return (p*p/x);
            }
        }
    }
};

int main() {
    Solution s;
    cout << s.myPow(2, 10) << endl;
    return 0;
}
