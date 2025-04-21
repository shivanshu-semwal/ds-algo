// prims algo
// don't work on directed graphs
// maintains a min heap to pick next edge

// using adjacency matrix
// you know source destination --> you know weight
// it make a set and assigns all vertex inf weight
// then pick one edge and all weights of it's adjacent elements
// only if they are small
// then pick the smallest one
// update the weights
// pick the smallest one again... and so on

// using adjacency list
//

#include <bits/stdc++.h>
using namespace std;

class MinHeapNode {
public:
    int v;      // destination vertex
    int weight; // weight
    MinHeapNode(int v, int weight) {
        this->v = v;
        this->weight = weight;
    }
    MinHeapNode() {
        v = 0;
        weight = 0;
    }
};

class MinHeap {
public:
    int size;
    int capacity;
    int *pos; // vertex no
    MinHeapNode **array;

    /* min heap */
    MinHeap(int capacity) {
        this->pos = new int[capacity];
        this->size = 0;
        this->capacity = capacity;
        this->array = new MinHeapNode *[capacity];
    }

    bool isEmpty() { return this->size == 0; }
    bool isIn(int v) { return ((pos[v] < size) ? true : false); }

    void swap(MinHeapNode **a, MinHeapNode **b) {
        MinHeapNode *t = *a;
        *a = *b;
        *b = t;
    }

    void minHeapify(int idx) {
        int smallest, left, right;
        smallest = idx;
        left = 2 * idx + 1;
        right = 2 * idx + 2;
        if (left < size && array[left]->weight < array[smallest]->weight) smallest = left;
        if (right < size && array[right]->weight < array[smallest]->weight) smallest = right;
        if (smallest != idx) {
            // Swap positions
            pos[array[smallest]->v] = idx;
            pos[array[idx]->v] = smallest;
            // Swap nodes
            swap(&array[smallest], &array[idx]);
            minHeapify(smallest);
        }
    }

    MinHeapNode *getMin() {
        if (isEmpty()) return NULL;

        MinHeapNode *root = array[0];
        MinHeapNode *lastNode = array[size - 1];

        array[0] = lastNode;
        // fix the positions
        pos[root->v] = this->size - 1; // root node is at the end
        pos[lastNode->v] = 0;          // lastnode is at the front
        size--;
        minHeapify(0);
        return root;
    }

    /* set the weight of a particular vertex in the heap */
    void setWeight(int v, int weight) {
        // assumption
        // the new weight set will always be less than the original one
        // so we will check to heapify in up direction not up
        int i = pos[v];            // get the postition of the vertex
        array[i]->weight = weight; // set the value for that vertex

        /* heapify bottom up */
        while (i && array[i]->weight < array[(i - 1) / 2]->weight) {
            pos[array[i]->v] = (i - 1) / 2;
            pos[array[(i - 1) / 2]->v] = i;
            swap(&array[i], &array[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }
};

// To add an edge
void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt) {
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

// Print adjacency list representation ot graph
void printGraph(vector<pair<int, int>> adj[], int V) {
    int v, w;
    for (int u = 0; u < V; u++) {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it != adj[u].end(); it++) {
            v = it->first;
            w = it->second;
            cout << "\tNode " << v << " with edge weight =" << w << "\n";
        }
        cout << "\n";
    }
}

void printArr(int arr[], int n) {
    for (int i = 1; i < n; ++i)
        printf("%d - %d\n", arr[i], i);
}

void prims(vector<pair<int, int>> adj[], int V) {
    int parent[V];
    int weight[V];

    MinHeap minHeap = MinHeap(V);

    for (int v = 0; v < V; v++) {
        parent[v] = -1;
        weight[v] = INT_MAX;
        minHeap.array[v] = new MinHeapNode(v, weight[v]);
        minHeap.pos[v] = v;
    }

    weight[0] = 0;
    minHeap.array[0] = new MinHeapNode(0, weight[0]);
    minHeap.pos[0] = 0;
    minHeap.size = V;

    while (!minHeap.isEmpty()) {
        // get the vertex with minimum weight
        MinHeapNode *minHeapNode = minHeap.getMin();
        int u = minHeapNode->v;

        vector<pair<int, int>>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); i++) {
            int vtx = (*i).first;
            int wght = (*i).second;
            if (minHeap.isIn(vtx) && // if vtx is not in cut
                wght < weight[vtx]   // if the new weight is less)
            ) {
                weight[vtx] = wght;
                parent[vtx] = u;
                minHeap.setWeight(vtx, weight[vtx]);
            }
        }
    }
    // printArr(parent, V);
    cout << "source\tdest\tweight\n";
    for (int i = 0; i < V; i++) {
        cout << parent[i] << "\t" << i << "\t" << weight[i] << "\n";
    }
}

// Driver code
int main() {
    int V = 9;
    vector<pair<int, int>> adj[V];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 7, 8);
    addEdge(adj, 1, 2, 8);
    addEdge(adj, 1, 7, 11);
    addEdge(adj, 2, 3, 7);
    addEdge(adj, 2, 5, 4);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 3, 4, 9);
    addEdge(adj, 3, 5, 14);
    addEdge(adj, 4, 5, 10);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 1);
    addEdge(adj, 6, 8, 6);
    addEdge(adj, 7, 8, 7);
    // printGraph(adj, V);
    prims(adj, V);
    return 0;
}
