#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int n;  // Number of vertices
    list<int> *adj;  // Adjacency list

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);

public:
    Graph(int n);  
    void addEdge(int v, int w);
    void topoSort();  
};

// Constructor
Graph::Graph(int n) {
    this->n = n;
    adj = new list<int>[n]; 
}

// Function to add an edge to the graph
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

// DFS function for topological sorting
void Graph::topologicalSortUtil(int v, bool visited[], stack<int> &Stack) {
    visited[v] = true;  

    for (int neighbor : adj[v]) {
        if (!visited[neighbor])
            topologicalSortUtil(neighbor, visited, Stack);
    }

    Stack.push(v);
}

// Function to perform topological sorting
void Graph::topoSort() {
    stack<int> Stack;
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
        visited[i] = false;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topologicalSortUtil(i, visited, Stack);

    // Print the topological order in a single line
    while (!Stack.empty()) {
        cout << Stack.top();
        Stack.pop();
        if (!Stack.empty()) cout << " ";  // Avoid trailing space
    }
    cout << endl;

    delete[] visited;  
}

// Driver function
int main() {
    Graph g(6);
    g.addEdge(4, 2);
    g.addEdge(5, 1);
    g.addEdge(4, 0);
    g.addEdge(3, 1);
    g.addEdge(1, 3);
    g.addEdge(3, 2);

    g.topoSort();  // Output only the topological order

    return 0;
}
