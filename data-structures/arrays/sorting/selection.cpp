#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &a) {
    for (int i = 0; i < a.size(); i++) {
        int mini = i;
        for (int j = i + 1; j < a.size(); j++) {
            if (a[j] < a[mini]) mini = j;
        }
        int temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
    }
}

int main() {
    vector<int> a = {1, 4, 2, 5, 5, 6, 3, 3, 4};
    selection_sort(a);
    for (auto i : a) cout << i << " ";
    return 0;
}