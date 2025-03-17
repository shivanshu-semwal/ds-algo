#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int solve(vector<int> p, int i, int j) {
    if (i == j) return 0; // base condition
    if(dp[i][j] != -1) return dp[i][j];
    int min = INT_MAX; // answer to return
    for (int k = i; k < j; k++) { // check all sub arrays
        // split array into tow subarray
        int count = solve(p, i, k) + 
                    solve(p, k + 1, j) + 
                    p[i - 1] * p[k] * p[j]; // cost of combining two subarray
        if (count < min) min = count;
    }
    return dp[i][j] = min;
}

int main(){
    vector<int> arr = { 1, 2, 3, 4, 3 };
    int n = arr.size();
    dp = vector<vector<int>> (n+1, vector<int> (n+1, -1));
    cout << solve(arr, 1, n - 1);
    return 0;
}