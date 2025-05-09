#include<bits/stdc++.h>
using namespace std;

// cache the state results, state is represented by (W, n), values that change
vector<vector<int>> dp;

int knapSack(vector<int>wt, vector<int>val, int W, int n){
    // base case
    if (n == 0 || W == 0) return 0;

    // getting cache result
    if(dp[n][W] != -1) return dp[n][W];

    if (wt[n - 1] <= W)
        return dp[n][W] = max(
            val[n - 1] + knapSack(wt, val, W - wt[n - 1], n - 1),
            knapSack(wt, val, W, n - 1)
        );
    else
        return dp[n][W] = knapSack(wt, val, W, n - 1);
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.size();
    int W = 50;
    dp = vector<vector<int>> (n+1, vector<int>(W+1, -1));
    cout << knapSack(wt, val, W, n);
    return 0;
}