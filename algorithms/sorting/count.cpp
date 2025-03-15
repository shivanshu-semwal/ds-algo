#include <bits/stdc++.h>
using namespace std;

#define N 10

void count_sort(vector<int> &a) {
    vector<int> c(N, 0);
    vector<int> out(a.size(), 0);
    for (auto i : a) c[i]++;                             // relative freq
    for (int i = 1; i < c.size(); i++) c[i] += c[i - 1]; // cumulative freq
    // for (int i = 0; i < a.size(); i++) out[c[a[i] - 1]++] = a[i]; // unstable
    for (int i = a.size() - 1; i >= 0; i--) out[c[a[i]]-- - 1] = a[i]; // stable
    a = out;
}

int main() {
    vector<int> a = {1, 4, 0, 2, 5, 5, 6, 3, 3, 4};
    count_sort(a);
    for (auto i : a) cout << i << " ";
    return 0;
}