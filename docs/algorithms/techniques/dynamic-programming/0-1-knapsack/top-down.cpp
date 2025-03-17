#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    // state cache, (n, W) represented state
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // for base case solution is already 0, which is as initialized

    // finding solution for remaining problems

    // for iterating through the item state set
    for(int i=1;i<n+1;i++){
        // for iterating though the weight state sets
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j])
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][W];
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.size();
    int W = 50;
    cout << knapSack(W, wt, val, n);
    return 0;
}