#include <iostream>
#include <limits.h>

class AdjListNode {
public:
    int dest;
    int weight;
    AdjListNode *next;
    AdjListNode(int dest, int weight) {
        this->dest = dest;
        this->weight = weight;
        this->next = NULL;
    }
};

class AdjList {
public:
    AdjListNode *head;
};

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
            // The nodes to be swapped in min heap
            MinHeapNode *smallestNode = array[smallest];
            MinHeapNode *idxNode = array[idx];
            // Swap positions
            pos[smallestNode->v] = idx;
            pos[idxNode->v] = smallest;
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

class Graph {
public:
    int V;                 // no of vertexes
    struct AdjList *array; // adjacency list

    /* constructor */
    Graph(int V) {
        this->V = V;
        array = new AdjList[V];
        for (int i = 0; i < V; ++i)
            array[i].head = NULL;
    }

    void addEdge(int src, int dest, int weight) {
        AdjListNode *newNode = new AdjListNode(dest, weight);
        newNode->next = array[src].head;
        array[src].head = newNode;
        newNode = new AdjListNode(src, weight);
        newNode->next = array[dest].head;
        array[dest].head = newNode;
    }

    void PrimMST() {

        int parent[V];
        int weight[V];

        MinHeap minHeap = MinHeap(V);

        for (int v = 1; v < V; ++v) {
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
            MinHeapNode *minHeapNode = minHeap.getMin();
            int u = minHeapNode->v; // Store the extracted vertex number
            AdjListNode *pCrawl = array[u].head;
            while (pCrawl != NULL) {
                int v = pCrawl->dest;
                if (minHeap.isIn(v) && pCrawl->weight < weight[v]) {
                    weight[v] = pCrawl->weight;
                    parent[v] = u;
                    minHeap.setWeight(v, weight[v]);
                }
                pCrawl = pCrawl->next;
            }
        }
        printArr(parent, V);
    }

    /* print array */
    void printArr(int arr[], int n) {
        for (int i = 1; i < n; ++i)
            printf("%d - %d\n", arr[i], i);
    }
};

int main() {
    // Let us create the graph given in above fugure
    int V = 9;
    Graph g = Graph(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 8, 2);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
    g.PrimMST();

    return 0;
}
