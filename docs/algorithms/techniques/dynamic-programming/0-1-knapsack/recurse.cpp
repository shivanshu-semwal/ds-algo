#include<bits/stdc++.h>
using namespace std;

// only things that change represent state
// here state is -> (W, n)
int knapSack(
    vector<int>wt, // weight of items array
    vector<int>val, // value associated with each item
    int W, // amount of weight we can add to knapsack
    int n // current item + 1 number
){
    // base condition, when either knapsack is full, or items are over
    if (n == 0 || W == 0) return 0;

    // if current item can be stored in the knapsack
    if (wt[n - 1] <= W) {
        return max(
            val[n - 1] + knapSack( wt, val, W - wt[n - 1], n - 1),
            knapSack(wt, val, W, n - 1)
        );
    }
    else {
        return knapSack(wt, val, W, n - 1);
    }
}

int main(){
    vector<int> val = { 60, 100, 120 };
    vector<int> wt = { 10, 20, 30 };
    int n = val.size();
    int W = 50;
    cout << knapSack(wt, val, W, val.size());
    return 0;
}