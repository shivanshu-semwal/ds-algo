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