#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string units[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        string thous[] = {"M", "MM", "MMM"};
        string huns[] = {"C", "CC", "CCC", "CD"};
        string tens[] = {"X", "XX", "XXX", "XL"};

        int n = num;
        string ans;

        int thou = n / 1000;
        if (thou > 0) {
            ans = ans + thous[thou - 1];
        }
        n = n % 1000;
        if (n >= 900) {
            ans = ans + "CM";
            n = n % 900;
        }
        else {
            int fhun = n / 500;
            if (fhun > 0) {
                ans = ans + "D";
            }
            n = n % 500;
        }
        int hun = n / 100;
        if (hun > 0) {
            ans = ans + huns[hun - 1];
        }
        n = n % 100;
        if (n >= 90) {
            ans = ans + "XC";
            n = n % 90;
        }
        else {
            int fty = n / 50;
            if (fty > 0) {
                ans = ans + "L";
            }
            n = n % 50;
        }
        int ten = n / 10;
        if (ten > 0) {
            ans = ans + tens[ten - 1];
        }
        n = n % 10;
        int unit = n;
        if (unit > 0) {
            ans = ans + units[unit - 1];
        }

        return ans;
    }
};



int main() {
    Solution s;
    string res = s.intToRoman(49);
    cout << res << endl;
    return 0;

}
