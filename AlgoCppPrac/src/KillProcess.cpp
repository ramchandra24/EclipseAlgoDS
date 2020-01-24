/*
 * KillProcess.cpp
 *
 *  Created on: Jan 24, 2020
 *      Author: ram
 */
#include <bits/stdc++.h>

using namespace std;
class KillProcess {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        std::map<int, vector<int>> ppmap;
        for (int i = 0; i < ppid.size(); ++i) {
            ppmap[ppid[i]].push_back(pid[i]);
        }

        vector<int> result;
        result.push_back(kill);
        getAllChildren(result, ppmap, kill);
        return result;
    }

    void getAllChildren(vector<int> &result, std::map<int, vector<int>> &m,
            int node) {
        if (m.find(node) == m.end())
            return;
        vector<int> childNodes = m[node];
        for (int i = 0; i < childNodes.size(); ++i) {
            int child = childNodes[i];
            result.push_back(child);
            getAllChildren(result, m, child);
        }
    }
};

int main(int argc, char **argv) {
    KillProcess kp;
    vector<int> pid { 1, 3, 10, 5 };
    vector<int> ppid { 3, 0, 5, 3 };
    vector<int> res = kp.killProcess(pid, ppid, 5);
    for (auto i : res) {
        cout << i << endl;
    }
}

