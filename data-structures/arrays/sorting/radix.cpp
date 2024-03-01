#include <bits/stdc++.h>
using namespace std;

#define N 10 // N base of the number system used

void count_sort(vector<int> &a, int exp) {
    vector<int> out(a.size(), 0);
    vector<int> c(N + 1, 0);                      // count for the digits
    for (auto i : a) c[(i / exp) % 10]++;         // relative freq
    for (int i = 1; i < N; i++) c[i] += c[i - 1]; // cumulative freq
    for (int i = a.size() - 1; i >= 0; i--) out[--c[(a[i] / exp) % 10]] = a[i];
    a = out;
}

void radix_sort(vector<int> &a) {
    // calculate max to get max no of digits
    int m = *max_element(a.begin(), a.end());
    for (int exp = 1; m / exp > 0; exp *= 10) count_sort(a, exp);
}

int main() {
    vector<int> a = {170, 45, 75, 90, 802, 24, 2, 66};
    radix_sort(a);
    for (auto i : a) cout << i << " ";
    return 0;
}