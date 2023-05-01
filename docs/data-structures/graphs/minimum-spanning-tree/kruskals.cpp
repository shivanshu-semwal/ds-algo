// kruskal's algo
// sorting edges by weight
// will fail on directed graphs 
// because it is unable to detect cycle in the graph

#include <bits/stdc++.h>

using namespace std;

void printEdges(vector<pair<int, pair<int, int>>> edges) {
    for (auto i = edges.begin(); i != edges.end(); i++) {
        cout << (*i).first << "=" << (*i).second.first << "," << (*i).second.second << endl;
    }
}

int getParent(int *parent, const int i) {
    if (parent[i] < 0) {
        return i;
    } else {
        return getParent(parent, parent[i]);
    }
}

void weightedUnion(int *parent, int m, int n) {
    int pm = getParent(parent, m);
    int pn = getParent(parent, n);
    if (pm == pn) return;
    if (pm < pn) {
        parent[pm] = parent[pm] + parent[pn];
        parent[pn] = pm;
    } else {
        parent[pn] = parent[pn] + parent[pm];
        parent[pm] = pn;
    }
}

vector<pair<int, pair<int, int>>> *
kruskals(vector<pair<int, pair<int, int>>> graph, const int V) {
    // vector<pair<int, pair<int, int>>> res;
    vector<pair<int, pair<int, int>>> *res = new vector<pair<int, pair<int, int>>>;
    bool visited[V] = {false};

    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = -1;

    sort(graph.begin(), graph.end());

    for (auto i = graph.begin(); i != graph.end(); i++) {
        int source = (*i).second.first;
        int destination = (*i).second.second;
        int weight = (*i).first;
        cout << "source:: " << source << " destination:: " << destination << " weight:: " << weight << "\n";
        cout << "parent-source:: " << getParent(parent, source) << " parent-destination:: " << getParent(parent, destination) << "\n";
        if (getParent(parent, source) != getParent(parent, destination)) {
            cerr << "(kruskals):: adding edge (" << source << "->" << destination << "::" << weight << "\n";
            res->push_back(*i);
            weightedUnion(parent, source, destination);
        }
    }
    printEdges(*res);
    return res;
}

int main() {
    int v, e;
    // store the weighted graph edges
    vector<pair<int, pair<int, int>>> edges;
    vector<pair<int, pair<int, int>>> *result;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;
        edges.push_back(make_pair(weight, make_pair(source, destination)));
    }
    // now do prims algo
    printEdges(edges);
    result = kruskals(edges, v);
    printEdges(*result);
    return 0;
}