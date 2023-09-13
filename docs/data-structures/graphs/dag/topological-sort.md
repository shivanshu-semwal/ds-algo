# Topological sort

> possible only for directed acyclic graphs

- find all possible topological graphs
- methods
    - dfs
    - khan's algo
- maximum edges that can be added to dag so it still remains dag
- longest path between pair of vertices
- longest path in dag


```cpp
#include <bits/stdc++.h>

using namespace std;

void topsortutil(vector<vector<int>> graph, stack<int> &st, int i, bool *visited) {
    cerr << "(top):: visiting " << i << " vertex\n";
    visited[i] = true;
    for (int j = 0; j < graph[i].size(); j++) {
        if (!visited[graph[i][j]]) {
            cerr << "(top):: visiting " << graph[i][j] << " now\n";
            topsortutil(graph, st, graph[i][j], visited);
        }
    }
    cerr << "(top):: pushing " << i << " \n";
    st.push(i);
}

void topological_sort(vector<vector<int>> graph) {
    /* make a visited array */
    bool visited[graph.size()] = {false};
    stack<int> st;
    for (int i = 0; i < graph.size(); i++) {
        if (!visited[i]) {
            cerr << "(top_sort):: edge " << i << " not visited -> visiting\n";
            topsortutil(graph, st, i, visited);
        }
    }

    while (!st.empty()) {
        cout << st.top() << "->";
        st.pop();
    }
}

int main() {
    int v; // no of vertices
    int e; // no of edges
    cout << "no of edges: ";
    cin >> e;
    cout << "no of vertices: ";
    cin >> v;

    vector<vector<int>> graph(v); // make a graph to store v vertices

    // now insert edges in int
    cout << "enter the edges now in form (source, destination)::\n";
    for (int i = 0; i < e; i++) {
        int source, destination;
        cin >> source >> destination;
        graph[source].push_back(destination); // insert the edge
    }

    topological_sort(graph);

    return 0;
}
```