// all pair shortest path
// use transtitive property

#include <bits/stdc++.h>

#define INF 99999

using namespace std;

void printMatrix(vector<int> graph[]) {
    cout << "\n";
    for (int i = 0; i < (*graph).size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            if (graph[i][j] == INF) {
                cout << "*\t";
                continue;
            }
            cout << graph[i][j] << "\t";
        }
        cout << "\n";
    }
}

void floyd(vector<int> graph[], int V) {
    vector<int> dist[V];

    for (int i = 0; i < V; i++) {
        dist[i] = graph[i];
    }

    cout << "(flyod):: printing dist ";
    printMatrix(dist);

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            for (int k = 0; k < V; k++) {
                // if (dist[i][j] == INT_MAX) {
                //     // cannot be connected
                //     if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                //         // still cannot be reached
                //         dist[i][j] == INT_MAX;
                //     } else {
                //         dist[i][j] = dist[i][k] + dist[k][j];
                //     }
                // } else if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) {
                //     // don't change
                //     dist[i][j] = dist[i][j];
                // }
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        cout << "(flyod):: printing distance_" << i;
        printMatrix(dist);
    }

    cout << "(flyod):: printing dist final ";
    printMatrix(dist);
}

int main() {
    int V = 4;
    vector<int> graph[V] = {
        {0, 12, INF, 1},
        {12, 0, 4, 7},
        {INF, 4, 0, 3},
        {1, 7, 3, 0}};

    cout << "(main):: printing graph";
    printMatrix(graph);

    // Print the solution
    floyd(graph, V);
    cout << "(main):: printing graph after flyod";
    printMatrix(graph);
    return 0;
}