#include <bits/stdc++.h>
using namespace std;

// state -> (i, j)
int solve(vector<int> p, int i, int j) {
    if (i == j) return 0; // base condition
    int min = INT_MAX; // answer to return
    for (int k = i; k < j; k++) { // check all sub arrays
        // split array into tow subarray
        int count = solve(p, i, k) + 
                    solve(p, k + 1, j) + 
                    p[i - 1] * p[k] * p[j]; // cost of combining two subarray
        if (count < min) min = count;
    }
    return min;
}

int main(){
    vector<int> arr = { 1, 2, 3, 4, 3 };
    cout << solve(arr, 1, arr.size() - 1);
    return 0;
}