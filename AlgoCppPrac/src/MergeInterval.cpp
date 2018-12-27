#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;

        sort(intervals.begin(), intervals.end(), comp);
//        int i = 0;
        int start = 0;
        int end = start;
        int endtime;
        if (intervals.size() > 0) {
            endtime = intervals[start].end;
        }
        while (start < intervals.size() && end < intervals.size()) {
            if (intervals[end].start <= endtime) {
                if (intervals[end].end > endtime) {
                    endtime = intervals[end].end;
                }
                ++end;
            }
            else {
                res.push_back(Interval(intervals[start].start, endtime));
                start = end;
            }
        }
        if (start != end) {
            res.push_back(Interval(intervals[start].start, endtime));
        }

        return res;
    }

    static bool comp(Interval a, Interval b) {
        return ((a.start) <= (b.start));
    }

    void printInt(vector<Interval> in) {
        for (auto it = in.begin(); it != in.end(); ++it) {
            cout << it->start << " : " << it->end << endl;
        }
        cout << endl;
    }
};

int main() {
    Solution s;
    vector<Interval> in = {{1, 1}};
    s.printInt(in);
    vector<Interval> res = s.merge(in);
    s.printInt(res);
    return 0;
}
