#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    tuple<int, int> getMaxDiff(vector<int> arr) {
        tuple<int, int> index(-1, -1);
        int lindex = arr.size() - 1;
        int sindex = lindex;
        int maxdiff = arr[lindex] - arr[sindex];

        for (int i = arr.size() - 2; i >= 0; --i) {
            if (arr[lindex] - arr[i] > maxdiff) {
                maxdiff = arr[lindex] - arr[i];
                sindex = i;
                index = make_tuple(lindex, sindex);
            }
            else if (arr[i] > arr[lindex]) {
                //index = make_tuple(lindex, sindex);
                lindex = i;
                sindex = i;
            }
        }

        return index;
    }

};


int main() {

    vector<int> arr = {2, 9, 5, 1, 6, 2, 8};
    Solution s;

    tuple<int, int> index = s.getMaxDiff(arr);
    cout << get<0>(index) << ", " << get<1>(index) << endl;
    return 0;
}
