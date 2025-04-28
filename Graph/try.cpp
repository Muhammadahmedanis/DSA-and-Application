#include <iostream>
using namespace std;

int main() {
    int vertices, isDirected;

    cout << "\nEnter the number of vertices: ";
    cin >> vertices;

    cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
    cin >> isDirected;

    int graph[100][100] = {0}; // initialized to 0

    int edges;
    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter the edges (format: from to):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        
        if(isDirected){
            graph[u][v] = 1;
        }else{
            graph[u][v] = 1; // edge from u to v
            if (!isDirected) {
                graph[v][u] = 1; // for undirected graph
            }
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for (int i = 0; i < vertices; ++i) {
        for (int j = 0; j < vertices; ++j) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
    //  return 0;
    int vertex;
    cout<<"\nEnter vertex to find its degree: ";
    cin>>vertex;
    if(!isDirected){
    int degree = 0;
        for(int i = 0; i < vertices; i++){
            if(graph[vertex][i] == 1){
                degree++;
            }
        }
        cout << "Degree of vertex " << vertex << " = " << degree << endl;
    }else{
        int inDegree = 0;
        int outDegree = 0;
        for(int i = 0; i < vertices; i++){
             if(graph[i][vertex] == 1){
                inDegree++;
            }
        }
        
        for(int j = 0; j < vertices; j++){
             if(graph[vertex][j] == 1){
                outDegree++;
            }
        }
        
        cout << "In-degree of vertex " << vertex << " = " << inDegree << endl;
        cout << "Out-degree of vertex " << vertex << " = " << outDegree << endl;
    }   
}






#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void bfs(vector<vector<int>>& graph, vector<bool>& visited, int start){
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        
        for(int i = 0; i < graph.size(); i++){
            if(graph[node][i] == 1 && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

void bfsTraversal(vector<vector<int>>& graph, int v){
    vector<bool> visited(v, false);
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            bfs(graph, visited, i);
        }
    }
}


void dfsTraversal(vector<vector<int>>& graph, int v){
    vector<bool> visited(v, false);
    stack<int> st;
    
    for(int i = 0; i < v; i++){
        if(!visited[i]){
            st.push(i);
            
            while(!st.empty()){
                int node = st.top();
                st.pop();
                
                if(!visited[node]){
                    visited[node] = true;
                    cout<<node<<" ";
                }
                for(int j = graph[node].size()-1;  j >= 0; j--){
                    int neighbor = graph[node][j];
                    if(!visited[neighbor]){
                        st.push(neighbor);
                    }
                }
            }
        }
    }
}




int main() {
    int vertices, isDirected, edges;
    cout<<"Enter number of vertices: ";
    cin>>vertices;
    
    cout << "Enter 1 for Directed Graph, 0 for Undirected Graph: ";
    cin >> isDirected;
    
    vector<vector<int>> graph(vertices, vector<int>(vertices, 0));
    
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter the edges (format: from to):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cout << "Edge " << i + 1 << ": ";
        cin >> u >> v;
        
        graph[u][v] = 1;
        if (!isDirected) {
            graph[v][u] = 1; // for undirected graph
        }
    }

    cout << "\nAdjacency Matrix:\n";
    for(int i = 0; i < vertices; i++){
        for(int j = 0; j < vertices; j++){
            cout<<graph[i][j]<<" ";            
        }
        cout<<endl;
    }
    
    cout<<"\nBFS Traversal: ";
    bfsTraversal(graph, vertices);
    
    cout<<"\nDFS Traversal: ";
    dfsTraversal(graph, vertices);

    return 0;
}