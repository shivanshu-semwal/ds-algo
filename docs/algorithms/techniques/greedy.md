# Greedy Algorithms

- Are optimization algorithms where we have objective to
  maximize or minimize stuff.
- Here at each step we make a choice and choose the optimal
  case which will lead to solution.

## Activity Selection Problem

```cpp
#include <iostream>

using namespace std;

/*  
    greedy choice is to 
    always pick the next activity whose 
    finish time is least among the remaining activities 
    and 
    the start time is more than or equal to the finish time of the previously selected activity. 
*/

void printMaxActivities(int *s, int *f, int n) {
    // it is assumed that f is sorted
    // first activity is always selected
    int i = 0;
    cout << i << " ";

    for (int j = 1; j < n; j++) {
        if (s[j] > f[i]) {
            cout << j << " ";
            i = j;
        }
    }
}

int main() {
    int s[] = {1, 3, 0, 5, 8, 5};
    int f[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(s) / sizeof(s[0]);
    printMaxActivities(s, f, n);
    return 0;
}
```

## Job Sequencing Problem

## Job Sequencing Problem (Using Disjoint Set)

## Job Sequencing Problem - Loss Minimization

## Job Selection Problem - Loss Minimization Strategy | Set 2

## Huffman Coding

## Efficient Huffman Coding for sorted input

## Huffman Decoding

## Water Connection Problem

## Policemen catch thieves

## Minimum Swaps for Bracket Balancing

## Fitting Shelves Problem

## Assign Mice to Holes
