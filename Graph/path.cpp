#include <iostream>
#include <vector>
using namespace std;

// ------------------- Custom Stack -------------------
class Stack {
    vector<int> elements;
public:
    void push(int val) {
        elements.push_back(val);
    }

    void pop() {
        if (!elements.empty())
            elements.pop_back();
    }

    int top() {
        if (!elements.empty())
            return elements.back();
        return -1; // if empty
    }

    bool empty() {
        return elements.empty();
    }
};

// ------------------- Custom Queue -------------------
class Queue {
    vector<int> elements;
    int frontIndex = 0; // to simulate queue behavior efficiently
public:
    void push(int val) {
        elements.push_back(val);
    }

    void pop() {
        if (frontIndex < elements.size())
            frontIndex++;
    }

    int front() {
        if (frontIndex < elements.size())
            return elements[frontIndex];
        return -1; // if empty
    }

    bool empty() {
        return frontIndex >= elements.size();
    }
};

// ------------------- Function to print path -------------------
void printPath(vector<int>& parent, int src, int dest) {
    Stack path;
    int current = dest;

    while (current != -1) {
        path.push(current);
        current = parent[current];
    }

    if (path.top() != src) {
        cout << "No path found from " << src << " to " << dest << "." << endl;
        return;
    }

    cout << "Path from " << src << " to " << dest << ": ";
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
    cout << endl;
}

// ------------------- BFS Function -------------------
void bfs(vector<vector<int>>& graph, int vertices, int src, int dest) {
    Queue q;
    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);

    visited[src] = true;
    q.push(src);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < vertices; ++i) {
            if (graph[node][i] == 1 && !visited[i]) {
                visited[i] = true;
                parent[i] = node;
                q.push(i);

                if (i == dest) {
                    printPath(parent, src, dest);
                    return;
                }
            }
        }
    }

    cout << "No path found from " << src << " to " << dest << "." << endl;
}

// ------------------- Main Function -------------------
int main() {
    int vertices, isDirected;

    cout << "\nEnter the number of vertices: ";
    cin >> vertices;

    cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
    cin >> isDirected;

    vector<vector<int>> graph(vertices, vector<int>(vertices, 0)); // 2D vector graph

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: from to):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;

        graph[u][v] = 1;
        if (!isDirected) {
            graph[v][u] = 1;
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }

    int src, dest;
    cout << "\nEnter source node: ";
    cin >> src;
    cout << "Enter destination node: ";
    cin >> dest;

    bfs(graph, vertices, src, dest);

    return 0;
}
