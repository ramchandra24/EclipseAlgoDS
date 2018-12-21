#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        cout << "sign : " << sign << endl;
        unsigned long long divi = llabs((long long)dividend);
        unsigned long long div = llabs((long long)divisor);

        unsigned long long q = 0;
        unsigned long long temp = 0ULL;
        for(int i = 31; i >= 0; --i) {
            if ((temp + ((div) << i)) <= divi) {
                cout << "i : " << i << endl;
                temp += (div<< i);
                q |= 1 << i;
            }
        }

        int res;
        if (q > INT_MAX) {
            if (sign == 1) {
                res = INT_MAX;
            }
            else {
                res = INT_MIN;
            }
        }
        else {
            res = (int)q * sign;
        }
        return res;
    }
};

int main() {
    Solution s;
    int q = 1;
    cout << s.divide(-2147483648, 1) << endl;
    cout << "qu : " << q << endl;
    return 0;
}


