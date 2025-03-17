#include <bits/stdc++.h>
using namespaces std;
vector<vector<int>> dp;
int lcs(string X, string Y, int m, int n ){
    if (m == 0 || n == 0) return 0;
    if(dp[m][n]!=-1) return dp[m][n];
    if (X[m-1] == Y[n-1]) return dp[m][n] = 1 + lcs(X, Y, m-1, n-1);
    else return dp[m][n] = max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int main(){
    string s1 = "hithisisthis";
    string s2 = "hithias";
    dp = vector<vector<int>> (s1.length()+1, vector<int>(s2.length()+1, -1));
    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}