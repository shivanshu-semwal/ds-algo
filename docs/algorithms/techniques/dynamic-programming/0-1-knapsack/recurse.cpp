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
    int n = val.size();
    int W = 50;
    cout << knapSack(W, wt, val, val.size());
    return 0;
}