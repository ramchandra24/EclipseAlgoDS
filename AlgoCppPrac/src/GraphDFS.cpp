#include <bits/stdc++.h>
using namespace std;


class Graph {
    int numV;
    vector<vector<int>> adj;
public:
    Graph(int n) {
        numV = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void printG() {
        for (int i = 0; i < adj.size(); ++i) {
            cout << i << ": ";
            for (int j = 0; j < adj[i].size(); ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfsUtil(int s, vector<bool>& visited) {
        cout << s << " ";
        visited[s] = true;
        for(int i = 0; i < adj[s].size(); ++i) {
            if (!visited[adj[s][i]]) {
                dfsUtil(adj[s][i], visited);
            }
        }
    }

    void dfs() {
        vector<bool> visited(numV, false);
        for (int i = 0; i < numV; ++i) {
            if (!visited[i]) {
                dfsUtil(i, visited);
            }
        }
    }

};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(3, 2);
    g.addEdge(5, 2);
    g.addEdge(4, 1);
    g.printG();

    g.dfs();
    return 0;
}
