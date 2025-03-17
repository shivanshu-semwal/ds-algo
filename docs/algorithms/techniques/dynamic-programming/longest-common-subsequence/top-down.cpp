#include <bits/stdc++.h>
using namespaces std;

int lcs(string X, string Y, int m, int n ){
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
    
    // base case already initialized
    
    for(int i=1;i<m+1;i++){
        for(int j=1;j<n+1;j++){
            if(X[m-1] == X[n-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return dp[m][n];
}

int main(){
    string s1 = "hithisisthis";
    string s2 = "hithias";
    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}