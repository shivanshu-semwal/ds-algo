# Dynamic Programming

## 0/1 knapsack type problem

### description

- we are given
    - two arrays - one for the weight of item and one for the price
    - a value which is equal to the capacity of knapsack
- for each item we have a choice
    - we should take the item
    - we should not take the item
    - you cannot take half of the item

### recursive sol

```cpp
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] <= W)
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1)
        );
    else
        return knapSack(W, wt, val, n - 1);
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.szie();
    int W = 50;
    cout << knapSack(W, wt, val, val.size());
    return 0;
}
```

### memoization solution

```cpp
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
```

### top down approach

```cpp
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1;i<n+1;i++){
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
```

### practice que

- 0/1 knapsack
    - <https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1>
- subset sum problem
    - <https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1>
- equal sum partition
    - <https://leetcode.com/problems/partition-equal-subset-sum/>
- count no of subset with given sum
    - <https://www.geeksforgeeks.org/count-of-subsets-with-sum-equal-to-x/>
- minimum subset difference problem
    - <https://www.geeksforgeeks.org/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum/>
- count the number of subset with given difference
    - <https://www.geeksforgeeks.org/count-of-subsets-with-given-difference/>
- target sum
    - <https://leetcode.com/problems/target-sum/>
- <https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/>

## unbounded knapsack type problem

### description

- we are given
    - two arrays - one for the weight of item and one for the price
    - a value which is equal to the capacity of knapsack
- for each item we have a choice
    - we should take the item **multiple times**
    - we should not take the item
    - you cannot take half of the item

### recursive sol

```cpp
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    if (n == 0 || W == 0) return 0;
    if (wt[n - 1] <= W)
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n),
            knapSack(W, wt, val, n - 1)
        );
    else
        return knapSack(W, wt, val, n - 1);
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.szie();
    int W = 50;
    cout << knapSack(W, wt, val, val.size());
    return 0;
}
```

### memoization solution

```cpp
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> dp;
int knapSack(int W, vector<int>wt, vector<int>val, int n){
    if (n == 0 || W == 0) return 0;
    if(dp[n][W] != -1) return dp[n][W];
    if (wt[n - 1] <= W)
        return dp[n][W] = max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n),
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
```

### top down approach

```cpp
#include<bits/stdc++.h>
using namespace std;

int knapSack(int W, vector<int>wt, vector<int>val, int n){
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
    for(int i=1;i<n+1;i++){
        for(int j=1;j<W+1;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j])
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
```

### practice que

- unbounded knapsack
    - <https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/>
- rod cutting problem
    - <https://practice.geeksforgeeks.org/problems/rod-cutting0840/1>
- coin change problem - maximum no. of ways
    - <https://leetcode.com/problems/coin-change/>
- coin change problem - minimum no of coins

## longest common subsequence type problem

### description

- you are given an two array or and string
- to compare two ends of string and make some choice

### recursive code

```cpp
#include <bits/stdc++.h>
using namespaces std;

int lcs(string X, string Y, int m, int n ){
    if (m == 0 || n == 0) return 0;
    if (X[m-1] == Y[n-1]) return 1 + lcs(X, Y, m-1, n-1);
    else return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n));
}

int main(){
    string s1 = "hithisisthis";
    string s2 = "hithias";
    cout << lcs(s1, s2, s1.length(), s2.length());
    return 0;
}
```

### memoization sol

```cpp
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
```

### top down approach

```cpp
#include <bits/stdc++.h>
using namespaces std;

int lcs(string X, string Y, int m, int n ){
    vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, 0));
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
```

### practice problems

- longest common subsequence
    - <https://leetcode.com/problems/longest-common-subsequence/>
- longest common substring
    - <https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1>
- print longest common subsequence
- shortest common supersequence
    - <https://leetcode.com/problems/shortest-common-supersequence/>
- minimum no of insertion and deletions to convert string a to string b
    - <https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1>
- longest palindromic subsequence
- minimum no of deletions to make a string palindrome
- print shortest common supersequence
- longest repeating subsequence
    - <https://www.geeksforgeeks.org/longest-repeating-subsequence/>
    - <https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1>
- sequence pattern matching
- minimum no of insertions to make a string palindrome
    - <https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/>

## matrix chain multiplications type problem

### description

- you are given an array, or a string
- you have to calculate something which depends on the subarray between the range

### recursive code

```cpp
#include <bits/stdc++.h>
using namespace std;

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
```

### memoization sol

```cpp
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
```

### top down approach

```cpp
#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> p) {
    int n = p.size();
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

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
```

### practice question

- matrix chain multiplication
    - <https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1>
- palindrome partitioning
    - <https://leetcode.com/problems/palindrome-partitioning/>
- evaluate expression to true boolean parenthesization
    - <https://practice.geeksforgeeks.org/problems/boolean-parenthesization5610/1>
- scrambled string
    - <https://leetcode.com/problems/scramble-string/>
- egg dropping problem

## binary tree problems

### Description

- you are given a binary tree
- you calculate the result at each node

### solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    Node *left;
    Node *right;
    int val;
}

// final ans
int ans;

int solve(Node *root){
    // base case
    if(root==NULL) return 0;
    // hypothesis
    int left = solve(root->left);
    int right = solve(root->right);
    // induction
    // ans for node that it will pass to its parent
    int t_ans = max(l, r) + 1; 
    int c_ans = max(t_ans, l+r+1); // candidate ans
    ans = max(ans, c_ans);
    return t_ans;
}

int main(){
    return 0;
}
```

### practice problems

- diameter of tree problem
    - <https://www.geeksforgeeks.org/diameter-of-a-binary-tree-in-on-a-new-method/>
- maximum path sum from leaf node to leaf node
    - <https://practice.geeksforgeeks.org/problems/maximum-path-sum/1>
- maximum path sum from any node to any node
    - <https://practice.geeksforgeeks.org/problems/maximum-path-sum-from-any-node/1>
