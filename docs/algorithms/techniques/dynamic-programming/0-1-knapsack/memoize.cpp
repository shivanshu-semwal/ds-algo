#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    if (n == 0 || W == 0) return 0;
    if(dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1)
        );
    else
        return dp[n][W] = knapSack(W, wt, val, n - 1);
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.size();
    int W = 50;
    dp = vector<vector<int>> (n+1, vector<int>(W+1, -1));
    cout << knapSack(W, wt, val, n);
    return 0;
}