#include <iostream>
using namespace std;

struct Node{
    int vertex;
    Node* next;
    
    Node(int v){
        vertex = v;
        next = NULL;
    }
};

struct Graph{
    int v;
    Node** adj;
    
    
    Graph(int vertices){
        v = vertices;
        adj = new Node*[v];
        for(int i = 0; i < v; i++){
            adj[i] = nullptr;
        }
    }
    
    
    void addEdge(int src, int des, bool isDirected){
        Node* newNode = new Node(des);
        
        if(adj[src] == nullptr){
            adj[src] = newNode;
        }else{
            Node* temp = adj[src];
            while(temp -> next != nullptr){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
        
        if(!isDirected){
            Node* newNode2 = new Node(src);
            
            if(adj[des] == nullptr){
                adj[des] = newNode2;
            }else{
                Node* temp = adj[des];
                while(temp -> next != nullptr){
                    temp = temp -> next;
                }
                temp -> next = newNode2;
            }
        }
    }
    
    
    void printGraph(){
        for(int i = 0; i < v; i++){
            cout<<"Vertex "<<i<<": ";
            Node* temp = adj[i];
            while(temp != nullptr){
                cout<<temp -> vertex<<", ";
                temp = temp -> next;
            }
            cout<<"NULL "<<endl;
        }
    }
    
 void bfs(int start) {
        bool* visited = new bool[v]{false};
        int* queue = new int[v];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS Traversal: ";

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            Node* temp = adj[current];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    visited[temp->vertex] = true;
                    queue[rear++] = temp->vertex;
                }
                temp = temp->next;
            }
        }
        cout << endl;
    }
    
    
    void dfs(int start){
        bool* visited = new bool[v]{false};
        int* stack = new int[v];
        int top = -1;
        
        stack[++top] = start;
    
        cout << "DFS Traversal: ";
        
        while(top != -1){
            int current = stack[top--];
            if(!visited[current]){
                cout << current << " ";
                visited[current] = true;
            }
            Node* temp = adj[current];
            while(temp != nullptr){
                if(!visited[temp -> vertex]){
                    stack[++top] = temp -> vertex;
                }
                temp = temp -> next;
            }
        }
        cout<<endl;
    }
};






int main() {
    int vertices, edges, isDirected;

    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    cout << "Enter 1 for Directed graph, 0 for Undirected graph: ";
    cin >> isDirected;

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << "Enter edges (format: from to):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;

        g.addEdge(u, v, isDirected);
    }

    cout << "\nAdjacency List of the Graph:\n";
    g.printGraph();

    int start;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start;

    g.bfs(start);
    g.dfs(start);
    
    return 0;
}