#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    vector<vector<int>> adj;
public:
    Graph(int n) {
        this->V = n;
        adj.resize(n);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    void bfs(int source) {
        vector<bool> visited(V, false);
        queue<int> q;
        visited[source] = true;
        q.push(source);
        while (!q.empty()) {
            int s = q.front();
            cout << s << " ";
            q.pop();
            for (int i = 0; i < adj[s].size(); ++i) {
                if (!visited[adj[s][i]]) {
                    visited[adj[s][i]] = true;
                    q.push(adj[s][i]);
                }
            }
        }
    }

};


int main() {
    Graph g(6);

    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    g.bfs(0);
    return 0;
}
