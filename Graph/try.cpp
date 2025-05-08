// using array to represent graph

// #include <iostream>
// using namespace std;

// int main() {
//     int vertices, isDirected;

//     cout << "\nEnter the number of vertices: ";
//     cin >> vertices;

//     cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
//     cin >> isDirected;

//     int graph[100][100] = {0};

//     int edges;
//     cout << "Enter number of edges: ";
//     cin >> edges;

//     cout << "Enter the edges (format: from to):\n";
//     for (int i = 0; i < edges; ++i) {
//         int u, v;
//         cout << "Edge " << i + 1 << ": ";
//         cin >> u >> v;
        
//         if(isDirected){
//             graph[u][v] = 1;
//         }else{
//             graph[u][v] = 1; // edge from u to v
//             if (!isDirected) {
//                 graph[v][u] = 1; // for undirected graph
//             }
//         }
//     }

//     cout << "\nAdjacency Matrix:\n";
//     for (int i = 0; i < vertices; ++i) {
//         for (int j = 0; j < vertices; ++j) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }

//     int vertex;
//     cout<<"\nEnter vertex to find its degree: ";
//     cin>>vertex;
//     if(!isDirected){
//     int degree = 0;
//         for(int i = 0; i < vertices; i++){
//             if(graph[vertex][i] == 1){
//                 degree++;
//             }
//         }
//         cout << "Degree of vertex " << vertex << " = " << degree << endl;
//     }else{
//         int inDegree = 0;
//         int outDegree = 0;
//         for(int i = 0; i < vertices; i++){
//              if(graph[i][vertex] == 1){
//                 inDegree++;
//             }
//         }
        
//         for(int j = 0; j < vertices; j++){
//              if(graph[vertex][j] == 1){
//                 outDegree++;
//             }
//         }
        
//         cout << "In-degree of vertex " << vertex << " = " << inDegree << endl;
//         cout << "Out-degree of vertex " << vertex << " = " << outDegree << endl;
//     }   
// }






// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         cout << node << " ";

//         for (int i = 0; i < graph.size(); i++) {
//             if (graph[node][i] == 1 && !visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// bool isDeleted(vector<vector<int>>& graph, int vertex) {
//     for (int i = 0; i < graph.size(); i++) {
//         if (graph[vertex][i] == 1 || graph[i][vertex] == 1) {
//             return false;
//         }
//     }
//     return true;
// }

// void bfsTraversal(vector<vector<int>>& graph, int v) {
//     vector<bool> visited(v, false);
//     for (int i = 0; i < v; i++) {
//         if (!visited[i] && !isDeleted(graph, i)) {
//             bfs(graph, visited, i);
//         }
//     }
// }

// void dfsTraversal(vector<vector<int>>& graph, int v) {
//     vector<bool> visited(v, false);
//     stack<int> st;

//     for (int i = 0; i < v; i++) {
//         if (!visited[i] && !isDeleted(graph, i)) {
//             st.push(i);

//             while (!st.empty()) {
//                 int node = st.top();
//                 st.pop();

//                 if (!visited[node]) {
//                     visited[node] = true;
//                     cout << node << " ";
//                 }

//                 for (int j = graph[node].size() - 1; j >= 0; j--) {
//                     if (graph[node][j] == 1 && !visited[j]) {
//                         st.push(j);
//                     }
//                 }
//             }
//         }
//     }
// }

// void deleteEdge(vector<vector<int>>& graph, int src, int dest, bool isDirected) {
//     int n = graph.size();
//     if (src >= 0 && src < n && dest >= 0 && dest < n) {
//         graph[src][dest] = 0;
//         if (!isDirected) {
//             graph[dest][src] = 0; // For undirected graph
//         }
//         cout << "Edge from " << src << " to " << dest << " deleted.\n";
//     } else {
//         cout << "Invalid source or destination vertex.\n";
//     }
// }


// void deleteVertex(vector<vector<int>>& graph, int vertex) {
//     int n = graph.size();
//     for (int i = 0; i < n; i++) {
//         graph[vertex][i] = 0; // Remove all outgoing edges
//         graph[i][vertex] = 0; // Remove all incoming edges
//     }
//     cout << "Vertex " << vertex << " and all its connections deleted.\n";
// }

// bool cycleUtil(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& recStack) {
//     if (!visited[node]) {
//         visited[node] = true;
//         recStack[node] = true;

//         for (int i = 0; i < graph.size(); i++) {
//             if (graph[node][i] == 1) {
//                 if (!visited[i] && cycleUtil(graph, i, visited, recStack)) {
//                     return true;
//                 } else if (recStack[i]) {
//                     return true;
//                 }
//             }
//         }
//     }
//     recStack[node] = false;
//     return false;
// }

// bool isCyclic(vector<vector<int>>& graph) {
//     vector<bool> visited(graph.size(), false);
//     vector<bool> recStack(graph.size(), false);

//     for (int i = 0; i < graph.size(); i++) {
//         if (!isDeleted(graph, i) && cycleUtil(graph, i, visited, recStack)) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int vertices, isDirected, edges;
//     cout << "Enter number of vertices: ";
//     cin >> vertices;

//     cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
//     cin >> isDirected;

//     vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

//     cout << "Enter number of edges: ";
//     cin >> edges;
//     cout << "Enter the edges (format: from to):\n";
//     for (int i = 0; i < edges; ++i) {
//         int u, v;
//         cout << "Edge " << i + 1 << ": ";
//         cin >> u >> v;

//         graph[u][v] = 1;
//         if (!isDirected) {
//             graph[v][u] = 1; // for undirected graph
//         }
//     }

//     cout << "\nAdjacency Matrix:\n";
//     for (int i = 0; i < vertices; i++) {
//         for (int j = 0; j < vertices; j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << "\nBFS Traversal: ";
//     bfsTraversal(graph, vertices);

//     cout << "\nDFS Traversal: ";
//     dfsTraversal(graph, vertices);

//     if (isCyclic(graph)) {
//         cout << "\nThe graph contains a cycle.\n";
//     } else {
//         cout << "\nThe graph does not contain a cycle.\n";
//     }

//     int vertexToDelete;
//     cout << "\nEnter vertex to delete: ";
//     cin >> vertexToDelete;

//     if (vertexToDelete >= 0 && vertexToDelete < vertices) {
//         deleteVertex(graph, vertexToDelete);
//     } else {
//         cout << "Invalid vertex index.\n";
//     }
    
//     int src, dest;
//     cout << "\nEnter source and destination to delete an edge: ";
//     cin >> src >> dest;
//     deleteEdge(graph, src, dest, isDirected);

//     cout << "\nUpdated Adjacency Matrix:\n";
//     for (int i = 0; i < vertices; i++) {
//         for (int j = 0; j < vertices; j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }







// using char to represent graph

// #include <iostream>
// #include <vector>
// #include <queue>
// #include <stack>
// using namespace std;

// int charToIndex(char c) {
//     if (c >= 'A' && c <= 'Z') return c - 'A';
//     else if (c >= 'a' && c <= 'z') return c - 'a' + 26;
//     return -1;
// }

// char indexToChar(int i) {
//     if (i >= 0 && i < 26) return 'A' + i;
//     else if (i >= 26 && i < 52) return 'a' + (i - 26);
//     return '?';
// }

// void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start) {
//     queue<int> q;
//     q.push(start);
//     visited[start] = true;

//     while (!q.empty()) {
//         int node = q.front();
//         q.pop();
//         cout << indexToChar(node) << " ";

//         for (int i = 0; i < graph.size(); i++) {
//             if (graph[node][i] == 1 && !visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// bool isDeleted(vector<vector<int>>& graph, int vertex) {
//     for (int i = 0; i < graph.size(); i++) {
//         if (graph[vertex][i] == 1 || graph[i][vertex] == 1) {
//             return false;
//         }
//     }
//     return true;
// }

// void bfsTraversal(vector<vector<int>>& graph, int v) {
//     vector<bool> visited(v, false);
//     for (int i = 0; i < v; i++) {
//         if (!visited[i] && !isDeleted(graph, i)) {
//             bfs(graph, visited, i);
//         }
//     }
// }

// void dfsTraversal(vector<vector<int>>& graph, int v) {
//     vector<bool> visited(v, false);
//     stack<int> st;

//     for (int i = 0; i < v; i++) {
//         if (!visited[i] && !isDeleted(graph, i)) {
//             st.push(i);

//             while (!st.empty()) {
//                 int node = st.top();
//                 st.pop();

//                 if (!visited[node]) {
//                     visited[node] = true;
//                     cout << indexToChar(node) << " ";
//                 }

//                 for (int j = graph[node].size() - 1; j >= 0; j--) {
//                     if (graph[node][j] == 1 && !visited[j]) {
//                         st.push(j);
//                     }
//                 }
//             }
//         }
//     }
// }

// void deleteVertex(vector<vector<int>>& graph, int vertex) {
//     int n = graph.size();
//     for (int i = 0; i < n; i++) {
//         graph[vertex][i] = 0;
//         graph[i][vertex] = 0;
//     }
//     cout << "Vertex " << indexToChar(vertex) << " and all its connections deleted.\n";
// }


// void deleteEdge(vector<vector<int>>& graph, int src, int dest, bool isDirected) {
//     if (src >= 0 && src < graph.size() && dest >= 0 && dest < graph.size()) {
//         graph[src][dest] = 0;
//         if (!isDirected) {
//             graph[dest][src] = 0;
//         }
//         cout << "Edge from " << indexToChar(src) << " to " << indexToChar(dest) << " deleted.\n";
//     } else {
//         cout << "Invalid vertices for deletion.\n";
//     }
// }


// bool cycleUtil(vector<vector<int>>& graph, int node, vector<bool>& visited, vector<bool>& recStack) {
//     if (!visited[node]) {
//         visited[node] = true;
//         recStack[node] = true;

//         for (int i = 0; i < graph.size(); i++) {
//             if (graph[node][i] == 1) {
//                 if (!visited[i] && cycleUtil(graph, i, visited, recStack)) {
//                     return true;
//                 } else if (recStack[i]) {
//                     return true;
//                 }
//             }
//         }
//     }
//     recStack[node] = false;
//     return false;
// }

// bool isCyclic(vector<vector<int>>& graph) {
//     vector<bool> visited(graph.size(), false);
//     vector<bool> recStack(graph.size(), false);

//     for (int i = 0; i < graph.size(); i++) {
//         if (!isDeleted(graph, i) && cycleUtil(graph, i, visited, recStack)) {
//             return true;
//         }
//     }
//     return false;
// }

// int main() {
//     int vertices, isDirected, edges;
//     cout << "Enter number of vertices (max 52 for A-Z, a-z): ";
//     cin >> vertices;

//     if (vertices > 52) {
//         cout << "Maximum supported vertices are 52 (A-Z, a-z).\n";
//         return 1;
//     }

//     cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
//     cin >> isDirected;

//     vector<vector<int>> graph(vertices, vector<int>(vertices, 0));

//     cout << "Enter number of edges: ";
//     cin >> edges;

//     cout << "Enter the edges (format: from to, like A B or a b):\n";
//     for (int i = 0; i < edges; ++i) {
//         char fromChar, toChar;
//         cout << "Edge " << i + 1 << ": ";
//         cin >> fromChar >> toChar;

//         int u = charToIndex(fromChar);
//         int v = charToIndex(toChar);

//         if (u == -1 || v == -1 || u >= vertices || v >= vertices) {
//             cout << "Invalid edge. Skipping.\n";
//             continue;
//         }

//         graph[u][v] = 1;
//         if (!isDirected) {
//             graph[v][u] = 1;
//         }
//     }

//     cout << "\nAdjacency Matrix:\n  ";
//     for (int i = 0; i < vertices; i++) {
//         cout << indexToChar(i) << " ";
//     }
//     cout << "\n";
//     for (int i = 0; i < vertices; i++) {
//         cout << indexToChar(i) << " ";
//         for (int j = 0; j < vertices; j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }

//     cout << "\nBFS Traversal: ";
//     bfsTraversal(graph, vertices);

//     cout << "\nDFS Traversal: ";
//     dfsTraversal(graph, vertices);

//     if (isCyclic(graph)) {
//         cout << "\nThe graph contains a cycle.\n";
//     } else {
//         cout << "\nThe graph does not contain a cycle.\n";
//     }

//     char vertexChar;
//     cout << "\nEnter vertex to delete (e.g., A, b): ";
//     cin >> vertexChar;

//     int vertexToDelete = charToIndex(vertexChar);
//     if (vertexToDelete >= 0 && vertexToDelete < vertices) {
//         deleteVertex(graph, vertexToDelete);
//     } else {
//         cout << "Invalid vertex.\n";
//     }
    
//     char srcChar, destChar;
//     cout << "\nEnter edge to delete (format: from to, like A B): ";
//     cin >> srcChar >> destChar;
    
//     int src = charToIndex(srcChar);
//     int dest = charToIndex(destChar);
    
//     deleteEdge(graph, src, dest, isDirected);

//     cout << "\nUpdated Adjacency Matrix:\n  ";
//     for (int i = 0; i < vertices; i++) {
//         cout << indexToChar(i) << " ";
//     }
//     cout << "\n";
//     for (int i = 0; i < vertices; i++) {
//         cout << indexToChar(i) << " ";
//         for (int j = 0; j < vertices; j++) {
//             cout << graph[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }