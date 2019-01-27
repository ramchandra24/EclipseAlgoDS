#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void grayCodeUtil(bitset<32> &bits, vector<int> &res, int n) {
        if (n == 0) {
            //cout << "if " << bits.to_ulong() << endl;
            res.push_back((int)bits.to_ulong());
        }
        else {
            //cout << bits.to_ulong() << endl;
            grayCodeUtil(bits, res, n-1);
            bits.flip(n-1);
            grayCodeUtil(bits, res, n-1);
        }
    }

    vector<int> grayCode(int n) {
        vector<int> res;
        bitset<32> bits;
        grayCodeUtil(bits, res, n);
        return res;
    }

    void printvec(vector<int> v) {
        cout << endl;
        for (auto a : v) {
            cout << a << endl ;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<int> res = s.grayCode(4);
    s.printvec(res);

    return 0;
}
