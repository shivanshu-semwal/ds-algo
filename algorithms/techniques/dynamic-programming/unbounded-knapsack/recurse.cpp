#include<bits/stdc++.h>
using namespace std;

// state represented by (W, n)
int knapSack(vector<int>wt, vector<int>val, int W, int n){
    // base case, items are over or knapsack is full
    if (n == 0 || W == 0) return 0;
    // can we add current item
    if (wt[n - 1] <= W)
        return max(
            val[n - 1] + knapSack(wt, val, W - wt[n - 1], n), // use item and remain on same item
            knapSack(wt, val, W, n - 1) // mode to next item
        );
    else
        return knapSack(wt, val, W, n - 1); // move to next item
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.size();
    int W = 50;
    cout << knapSack(wt, val, W, val.size());
    return 0;
}