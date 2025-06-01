#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

bool compare(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

class Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    vector<Edge> edges;

    vector<int> parent;

    int findParent(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findParent(parent[u]);
    }

    void unionSets(int u, int v) {
        parent[findParent(u)] = findParent(v);
    }

public:
    Graph(int V) : V(V) {
        adj.resize(V);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        edges.push_back({u, v, w});
    }

    void primMST() {
        vector<bool> visited(V, false);
        vector<int> key(V, INT_MAX), parent(V, -1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        key[0] = 0;
        pq.push({0, 0});
        int totalCost = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;
            totalCost += key[u];

            for (const auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (!visited[v] && w < key[v]) {
                    key[v] = w;
                    parent[v] = u;
                    pq.push({w, v});
                }
            }
        }

        cout << "\nPrim's MST:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << " : " << key[i] << "\n";
        cout << "Total cost: " << totalCost << "\n";
    }

    void kruskalMST() {
        sort(edges.begin(), edges.end(), compare);
        parent.resize(V);
        for (int i = 0; i < V; i++) parent[i] = i;

        int totalCost = 0;
        cout << "\nKruskal's MST:\n";
        for (const auto &e : edges) {
            if (findParent(e.u) != findParent(e.v)) {
                unionSets(e.u, e.v);
                cout << e.u << " - " << e.v << " : " << e.w << "\n";
                totalCost += e.w;
            }
        }
        cout << "Total cost: " << totalCost << "\n";
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;

    Graph g(V);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }

    g.primMST();
    g.kruskalMST();

    return 0;
}



// output

// Enter number of vertices and edges: 5 7
// Enter edges (u v weight):
// 0 1 2
// 0 3 6
// 1 3 8
// 1 4 5
// 1 2 3
// 2 4 7
// 3 4 9

// Prim's MST:
// 0 - 1 : 2
// 1 - 2 : 3
// 0 - 3 : 6
// 1 - 4 : 5
// Total cost: 16

// Kruskal's MST:
// 0 - 1 : 2
// 1 - 2 : 3
// 1 - 4 : 5
// 0 - 3 : 6
// Total cost: 16