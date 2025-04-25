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