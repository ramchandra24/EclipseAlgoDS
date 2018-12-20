#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        dividend = abs(dividend);
        divisor = abs(divisor);

        unsigned long long q = 0;
        unsigned long long temp = 0L;
        for(int i = 31; i >= 0; --i) {
            if ((temp + ((unsigned long long)(divisor) << i)) <= dividend) {
                cout << "i : " << i << endl;
                temp += (unsigned long long)(divisor << i);
                q |= 1 << i;
            }
        }
        cout << q << endl;
        if (q > INT_MAX) {
            q = INT_MAX;
        }
        return sign * q;
    }
};

int main() {
    Solution s;
    int q = 1;
    cout << s.divide(INT_MIN, -1) << endl;
    cout << "qu : " << q << endl;
    return 0;
}


