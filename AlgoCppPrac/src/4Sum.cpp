#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class node {
        int i;
        int j;
        int sum;
    public:
        node(int i, int j, int sum) {
            this->i = i;
            this->j = j;
            this->sum = sum;
        }
        int geti() { return this->i; }
        int getj() { return this->j; }
        int getsum() { return this->sum; }
    };
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        vector<node> twos = twosums(nums);
        //sort(twos.begin(), twos.end());
        printnodes(twos);
        cout << endl;
        int sol = 0;
        std::map<vector<int>, int> m;

        for(int i = 0; i < twos.size(); ++i) {
            for(int j = 1 + nums.size() - i; j < twos.size(); ++j) {
                if ( twos[i].getsum() + twos[j].getsum() == target ) {
                    cout << "found target" << endl;
                    cout << twos[i].geti() << " : " << twos[i].getj() << " :: ";
                    cout << twos[j].geti() << " : " << twos[j].getj() << endl;
                    cout << "numbers : " << endl;
                    cout << nums[twos[i].geti()] << " : " << nums[twos[i].getj()] << " :: ";
                    cout << nums[twos[j].geti()] << " : " << nums[twos[j].getj()] << endl;
                    vector<int> ind;
                    ind.push_back(twos[i].geti());
                    ind.push_back(twos[i].getj());
                    ind.push_back(twos[j].geti());
                    ind.push_back(twos[j].getj());
                    sort(ind.begin(), ind.end());
                    if(ind[0] == ind[1] || ind[1] == ind[2] || ind[2] == ind[3]) {
                        continue;
                    }
                    vector<int> s;
                    s.push_back(nums[twos[i].geti()]);
                    s.push_back(nums[twos[i].getj()]);
                    s.push_back(nums[twos[j].geti()]);
                    s.push_back(nums[twos[j].getj()]);
                    sort(s.begin(), s.end());
                    if (m.find(s) == m.end()) {
                        res.push_back(s);
                        m.insert(make_pair(s, sol));
                        sol++;
                    }
                }
                else {
                    cout << i << " :: " << j << endl;
                }
            }
            cout << endl;
        }

        return res;
    }
    vector<node> twosums(vector<int> const& nums) {
        vector<node> res;
        for(int j = 0; j < nums.size()-1; ++j) {
            for(int i = j+1; i < nums.size(); ++i ) {
                res.push_back(node(j, i, nums[i] + nums[j]));
            }
        }
        return res;
    }

    void printresult(vector<vector<int>> const &n) {
        for (auto const& v : n) {
            cout << endl;
            printvec(v);
        }
    }

    void printnodes(vector<node> const &n) {
        for(auto v : n) {
            cout << v.geti() << " : " << v.getj() << " :: " << v.getsum() << endl;
        }
    }

    void printvec(vector<int> const& n) {
        cout << endl;
        for(auto v : n) {
            cout << v << " ";
        }
        cout << endl;
    }
};


int main() {
    Solution s;
    vector<int> inp = {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> sol = s.fourSum(inp, 0);
    s.printresult(sol);
    return 0;
}




