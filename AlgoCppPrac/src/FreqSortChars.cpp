/*
 * FreqSortChars.cpp
 *
 *  Created on: Jan 24, 2020
 *      Author: ram
 */
#include <bits/stdc++.h>
using namespace std;

class sortBy {
public:
    bool operator()(pair<char, int> a, pair<char, int> b) {
        if (a.second == b.second)
            return (a.first - b.first) > 0;
        return (a.second - b.second) < 0;
    }
};

class FreqSortChars {
public:
    string frequencySort(string s) {
        map<char, int> charCount;
        for (char c : s) {
            charCount[c]++;
        }
        priority_queue<pair<char, int>, vector<pair<char, int>>, sortBy> pq(
                charCount.begin(), charCount.end());
        string sb;
        while (!pq.empty()) {
            pair<char, int> p = pq.top();
            pq.pop();
            char ch = p.first;
            int count = p.second;
            while (count--) {
                sb = sb + ch;
            }
        }
        return sb;
    }
//    bool sortBy(pair<char, int> a, pair<char, int> b) {
//        if (a.second == b.second)
//            return (a.first - b.first) > 0;
//        return (a.second - b.second) > 0;
//    }
};

int main(int argc, char **argv) {
    FreqSortChars f;
    cout << f.frequencySort("tree") << endl;
}

