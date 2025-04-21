#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> p) {
    int n = p.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

    // length of subarray you will traverse
    for(int len=2;len<n+1;len++){
        for(int i=1;i<= n-len+1; i++){
            int j=i+len-1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int count = dp[i][k] + dp[i+1][k] + p[i - 1] * p[k] * p[j];
                dp[i][j] = min(dp[i][j], count);
            }
        }
    }
    return dp[n][b];
}

int main(){
    vector<int> arr = { 1, 2, 3, 4, 3 };
    int n = arr.size();
    cout << solve(arr, 1, n - 1);
    return 0;
}