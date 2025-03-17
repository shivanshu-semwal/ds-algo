#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 300005;

int bridgec;
vector<int> adj[MAX_N];
int dfs[MAX_N];
int low[MAX_N];
int cur;

void visit(int vertex, int parent) {
  cur++;
  dfs[vertex] = cur;
  low[vertex] = cur;

  for (int nxt : adj[vertex]) {
    if (dfs[nxt] == 0) {
      visit(nxt, vertex);
      low[vertex] = min(low[vertex], low[nxt]);
      if (low[nxt] > dfs[vertex]) {
        bridgec++;
      }
    } else if (nxt != parent) {
      low[vertex] = min(low[vertex], dfs[nxt]);
    }
  }
}

int main() {
  int vertexc, edgec;
  cin >> vertexc >> edgec;
  for (int i = 0; i < edgec; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  visit(1, 0);
  cout << bridgec << endl;
}
