#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    Node* next;
    int vertex;
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
        
        for(int i = 0; i < vertices; i++){
            adj[i] = nullptr;
        }
    };
    
    
    void addEdge(int src, int des){
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
    };
    
    
    void bfs(int start){
        bool* visited = new bool[v]{false};
        int* queue = new int[v];
        int front = 0, rear = 0;
        
        visited[start] = true;
        queue[rear++] = start;
        
        cout << "BFS Traversal: "; 
        while(front < rear){
            int current = queue[front++];
            cout<<current<<" ";
            Node* temp = adj[current];
            while(temp != nullptr){
                if(!visited[temp -> vertex]){
                    visited[temp -> vertex] = true;
                    queue[rear++] = temp -> vertex;
                }
                temp = temp -> next;
            }
        }
        cout << endl;
    };
    
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
    };
    
    
    
    bool isCyclicUtil(int node, bool* visited, bool* recStack){
        visited[node] = true;
        recStack[node] = true;
        
        Node* temp = adj[node];
        while(temp != nullptr){
            int neighbor = temp -> vertex;
            if(!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)){
                return true;
            }else if (recStack[neighbor]){
                return true;
            }
            temp = temp -> next;
        }
        recStack[node] = false;
        return false;
    };
    
    
    bool isCyclic(){
        bool* visited = new bool[v]{false};
        bool* recStack = new bool[v]{false};
        
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                if(isCyclicUtil(i, visited, recStack)){
                    return true;
                }
            }
        }
        return false;
    };
    
    void deleteEdge(int src, int des){
        Node* temp = adj[src];
        Node* prev = nullptr;
        
        while(temp != nullptr){
            if(temp -> vertex == des){
                if(prev == nullptr){
                    adj[src] = temp -> next;
                }else{
                    prev -> next = temp -> next;
                }
                
                delete temp;
                return;
            }
            prev = temp;
            temp = temp -> next;
        }
    }
    
    
    void deleteVertex(int data){
        //  Delete all outgoing edges from vertexToDelete
        Node* temp = adj[data];
        while(temp != nullptr){
            Node* toDelete = temp;
            temp = temp -> next;
            delete toDelete;
        }
        adj[data] = nullptr;
        
        // Delete all incoming edges to vertexToDelete
        for(int i = 0; i < v; i++){
            if(i != data){
                deleteEdge(i, data);
            }
        }
        
    }
    
    
    void printGraph(){
        for(int i = 0; i < v; i++){
            cout<<"Vertex "<< i<<": ";
            Node* temp = adj[i];
            while(temp != nullptr){
                cout<< temp -> vertex<<", ";
                temp = temp -> next;
            }
            cout<<"NULL"<<endl;
        }
    };
    
};


int main() {
    int vertices, edges;
    cout<<"* Adjancy list *"<<endl;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    
    cout<<"Enter number of edges: ";
    cin>>edges;
    
    Graph g(vertices);
    
    cout << "Enter edges (format: from to):" << endl;
    for(int i = 0; i < edges; i++){
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        
        if(u >= 0 && u < vertices && v >= 0 && v < vertices){
            g.addEdge(u, v);
        } else {
            cout << "Invalid edge input!" << endl;
            i--;
        }
    } 
    
    cout << "\nAdjacency List of the Graph:\n";
    g.printGraph();    
    
    int start;
    cout << "\nEnter starting vertex for BFS and DFS: ";
    cin >> start;

    if(start >= 0 && start < vertices){
        g.bfs(start);
        g.dfs(start);
    } else {
        cout << "Invalid starting vertex!" << endl;
    }
    
    if(g.isCyclic()){
        cout<<"\nCycle exists in the graph.";
    }else{
        cout<<"\nNo cycle in the graph.";
    }
    
    int toDelete;
    cout << "\nEnter vertex to delete (removes its edges too): ";
    cin >> toDelete;
    if(toDelete >= 0 && toDelete < vertices){
        g.deleteVertex(toDelete);
        cout << "\nGraph after deleting vertex " << toDelete << ":\n";
        g.printGraph();
    }else{
        cout << "\nInvalid vertex.";
    }
    
    return 0;
}






//  char handle
// #include <iostream>
// using namespace std;

// int charToIndex(char ch) {
//     if (ch >= 'A' && ch <= 'Z') return ch - 'A';
//     if (ch >= 'a' && ch <= 'z') return ch - 'a' + 26;
//     return -1;
// }

// char indexToChar(int index) {
//     if (index >= 0 && index <= 25) return 'A' + index;
//     if (index >= 26 && index <= 51) return 'a' + (index - 26);
//     return '?';
// }

// struct Node {
//     Node* next;
//     int vertex;
//     Node(int v) {
//         vertex = v;
//         next = nullptr;
//     }
// };

// struct Graph {
//     int v;
//     Node** adj;
//     bool* deleted;

//     Graph(int vertices) {
//         v = vertices;
//         adj = new Node * [v];
//         deleted = new bool[v]{false};

//         for (int i = 0; i < v; i++) {
//             adj[i] = nullptr;
//         }
//     }

//     void addEdge(int src, int des) {
//         Node* newNode = new Node(des);
//         newNode->next = adj[src];
//         adj[src] = newNode;
//     }

//     void bfs(int start) {
//         if (deleted[start]) {
//             cout << "Start vertex is deleted.\n";
//             return;
//         }

//         bool* visited = new bool[v]{false};
//         int* queue = new int[v];
//         int front = 0, rear = 0;

//         visited[start] = true;
//         queue[rear++] = start;

//         cout << "BFS Traversal: ";
//         while (front < rear) {
//             int current = queue[front++];
//             if (deleted[current]) continue;

//             cout << indexToChar(current) << " ";
//             Node* temp = adj[current];
//             while (temp != nullptr) {
//                 if (!visited[temp->vertex] && !deleted[temp->vertex]) {
//                     visited[temp->vertex] = true;
//                     queue[rear++] = temp->vertex;
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//         delete[] visited;
//         delete[] queue;
//     }

//     void dfs(int start) {
//         if (deleted[start]) {
//             cout << "Start vertex is deleted.\n";
//             return;
//         }

//         bool* visited = new bool[v]{false};
//         int* stack = new int[v];
//         int top = -1;
//         stack[++top] = start;

//         cout << "DFS Traversal: ";
//         while (top != -1) {
//             int current = stack[top--];
//             if (!visited[current] && !deleted[current]) {
//                 cout << indexToChar(current) << " ";
//                 visited[current] = true;
//             }

//             Node* temp = adj[current];
//             while (temp != nullptr) {
//                 if (!visited[temp->vertex] && !deleted[temp->vertex]) {
//                     stack[++top] = temp->vertex;
//                 }
//                 temp = temp->next;
//             }
//         }
//         cout << endl;
//         delete[] visited;
//         delete[] stack;
//     }

//     bool isCyclicUtil(int node, bool* visited, bool* recStack) {
//         visited[node] = true;
//         recStack[node] = true;

//         Node* temp = adj[node];
//         while (temp != nullptr) {
//             int neighbor = temp->vertex;
//             if (deleted[neighbor]) {
//                 temp = temp->next;
//                 continue;
//             }

//             if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack)) {
//                 return true;
//             } else if (recStack[neighbor]) {
//                 return true;
//             }
//             temp = temp->next;
//         }
//         recStack[node] = false;
//         return false;
//     }

//     bool isCyclic() {
//         bool* visited = new bool[v]{false};
//         bool* recStack = new bool[v]{false};

//         for (int i = 0; i < v; i++) {
//             if (!deleted[i] && !visited[i]) {
//                 if (isCyclicUtil(i, visited, recStack)) {
//                     delete[] visited;
//                     delete[] recStack;
//                     return true;
//                 }
//             }
//         }

//         delete[] visited;
//         delete[] recStack;
//         return false;
//     }

//     void deleteEdge(int src, int des) {
//         Node* temp = adj[src];
//         Node* prev = nullptr;

//         while (temp != nullptr) {
//             if (temp->vertex == des) {
//                 if (prev == nullptr) {
//                     adj[src] = temp->next;
//                 } else {
//                     prev->next = temp->next;
//                 }
//                 delete temp;
//                 return;
//             }
//             prev = temp;
//             temp = temp->next;
//         }
//     }

//     void deleteVertex(int data) {
//         Node* temp = adj[data];
//         while (temp != nullptr) {
//             Node* toDelete = temp;
//             temp = temp->next;
//             delete toDelete;
//         }
//         adj[data] = nullptr;
//         deleted[data] = true;

//         for (int i = 0; i < v; i++) {
//             if (i != data) {
//                 deleteEdge(i, data);
//             }
//         }
//     }

//     void printGraph() {
//         for (int i = 0; i < v; i++) {
//             if (deleted[i]) continue;
//             cout << "Vertex " << indexToChar(i) << ": ";
//             Node* temp = adj[i];
//             while (temp != nullptr) {
//                 if (!deleted[temp->vertex]) {
//                     cout << indexToChar(temp->vertex) << " -> ";
//                 }
//                 temp = temp->next;
//             }
//             cout << "NULL" << endl;
//         }
//     }

//     ~Graph() {
//         for (int i = 0; i < v; i++) {
//             Node* temp = adj[i];
//             while (temp != nullptr) {
//                 Node* next = temp->next;
//                 delete temp;
//                 temp = next;
//             }
//         }
//         delete[] adj;
//         delete[] deleted;
//     }
// };

// int main() {
//     int vertices, edges;
//     cout << "* Adjacency List Graph *" << endl;
//     cout << "Enter number of vertices (up to 52 for A-Z, a-z): ";
//     cin >> vertices;

//     if (vertices > 52 || vertices < 1) {
//         cout << "Only 1 to 52 vertices supported." << endl;
//         return -1;
//     }

//     cout << "Enter number of edges: ";
//     cin >> edges;

//     Graph g(vertices);

//     cout << "Enter edges (format: from to, e.g. A b):" << endl;
//     for (int i = 0; i < edges; i++) {
//         char from, to;
//         cout << "Edge " << i + 1 << ": ";
//         cin >> from >> to;

//         int u = charToIndex(from);
//         int v = charToIndex(to);

//         if (u == -1 || v == -1 || u >= vertices || v >= vertices) {
//             cout << "Invalid input! Must be A-Z or a-z within vertex count." << endl;
//             i--;
//             continue;
//         }

//         g.addEdge(u, v);
//     }

//     cout << "\nAdjacency List of the Graph:\n";
//     g.printGraph();

//     char startChar;
//     cout << "\nEnter starting vertex for BFS and DFS (A-Z or a-z): ";
//     cin >> startChar;
//     int start = charToIndex(startChar);
//     if (start == -1 || start >= vertices) {
//         cout << "Invalid vertex input!" << endl;
//         return -1;
//     }

//     g.bfs(start);
//     g.dfs(start);

//     if (g.isCyclic()) {
//         cout << "\nCycle exists in the graph." << endl;
//     } else {
//         cout << "\nNo cycle in the graph." << endl;
//     }

//     char delChar;
//     cout << "\nEnter vertex to delete (A-Z or a-z): ";
//     cin >> delChar;
//     int toDelete = charToIndex(delChar);

//     if (toDelete == -1 || toDelete >= vertices) {
//         cout << "Invalid vertex." << endl;
//     } else {
//         g.deleteVertex(toDelete);
//         cout << "\nGraph after deleting vertex " << delChar << ":\n";
//         g.printGraph();
//     }

//     return 0;
// }
