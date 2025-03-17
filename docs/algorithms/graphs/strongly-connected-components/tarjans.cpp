#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
  vector<vector<int>> adj;
  vector<bool> visited;
  vector<int> discovery_time;
  vector<int> ancestor;
  vector<bool> isAP;
  int V;

  Graph(int V) {
    this->V = V;
    visited = vector<bool>(V, false);
    isAP = vector<bool>(V, false);
    discovery_time = vector<int>(V, 0);
    ancestor = vector<int>(V);
    adj = vector<vector<int>>(V, vector<int>());
  }

  void add_edge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void APUtil(int& time, int parent, int u) {
    int children = 0;
    visited[u] = true;
    discovery_time[u] = ancestor[u] = time++;

    for (auto v : adj[u]) {
      if (!visited[v]) {
        children++;
        APUtil(time, u, v);
        // update the ancestor of current node
        ancestor[u] = min(ancestor[u], ancestor[v]);
        if (parent != -1) // if current node is root node
          if (ancestor[v] >= discovery_time[u])
            // and it cannot reach any ancestors of its parent
            isAP[u] = true;
      } else {
        if (v != parent)
          // if v is not parent of current node
          ancestor[u] = min(ancestor[u], discovery_time[v]);
      }
    }
    // root parent with more than one children
    if (parent == -1 && children > 1)
      isAP[u] = true;
  }

  vector<int> getAP() {
    int time = 0, par = -1;
    for (int i = 0; i < V; i++)
      if (!visited[i])
        APUtil(time, par, i);

    vector<int> ans;
    for (int i = 0; i < V; i++)
      if (isAP[i])
        ans.push_back(i);
    return ans;
  }
};

int main() {
  int V = 5;
  vector<vector<int>> edges = {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};

  Graph G(V);
  for (auto& edge : edges)
    G.add_edge(edge[0], edge[1]);
  vector<int> ans = G.getAP();
  return 0;
}