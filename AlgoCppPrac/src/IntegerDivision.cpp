#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {

    }

    bool divideBySub(int divi, int div, int odiv, int& q) {
        if (divi - div <= odiv) {
            if (divi - div == odiv){
                ++q;
            }
            if (divi - div >= 0) {
                return true;
            }
            return false;
        }
        q += q;
        if (divideBySub(divi, div+div, odiv, q)) {
            return true;
        }
        q -= (q >> 2);
        return divideBySub(divi, (div + (div>>1)), odiv, q);

    }

};

int main() {
    Solution s;
    int q = 1;
    cout << s.divideBySub(100, 3, 3, q) << endl;
    cout << "qu : " << q << endl;
    return 0;
}


