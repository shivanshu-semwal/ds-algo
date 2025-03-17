#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a) {
    int key = 0;
    for (int i = 1; i < a.size(); i++) {
        key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[++j] = key;
    }
}

int main() {
    vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
    insertion_sort(a);
    for (auto i : a) cout << i << " ";
    return 0;
}