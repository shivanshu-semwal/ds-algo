#include <bits/stdc++.h>
using namespaces std;

// state is represented by (m, n)
// m - 1 th item and n-1 th item
int lcs(string X, string Y, int m, int n ){
    // base case, we reached the end
    if (m == 0 || n == 0) return 0;

    // if both are equal
    if (X[m-1] == Y[n-1]) 
        return 1 + lcs(X, Y, m-1, n-1);
    else 
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int main(){
    string s1 = "hithisisthis";
    string s2 = "hithias";
    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}