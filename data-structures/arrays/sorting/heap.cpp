#include <bits/stdc++.h>
using namespace std;

void heap_sort(vector<int> &a) {
    /* make a min heap using heapify O(n)*/
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq(std::greater<int>(), a);
    for (int i = 0; i < a.size(); i++) {
        a[i] = pq.top();
        pq.pop();
    }
}

int main() {
    vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
    heap_sort(a);
    for (auto i : a) cout << i << " ";
    return 0;
}