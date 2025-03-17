# Monotonic Stack

- when to use stack
- when you have $O(n^2)$ solution and the inner loop is dependent on j
    - then you can have better solution in $O(n)$

```c
for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
        // n^2 code complexity
        // actually - n(n+1)/2 time complexity
        // so we can use stack here to make it better
    }
}
```

- note that in these solutions the amortized time complexity will be $O(n)$
    even though you will be using a while loop inside a for loop.

## Problems

### Nearest greater to Right

```cpp
int n = arr.size();
vector<int> ans(n, -1);

stack<int> st;
for(int i=n-1;i>=0;i--){
    // check the next greater element to right of this
    while(!st.empty() && st.top() <= arr[i]){
        st.pop();
    }
    
    // fill the next greater element
    if(st.empty()) ans[i] = -1;
    else ans[i] = st.top();
    
    // push curr one, as it can be a candidate for the other elements
    st.push(arr[i]);
}
```

<https://leetcode.com/problems/next-greater-element-i/>

Similarly other variations are possible.

- Nearest greater to left
- Nearest smaller to right
- Nearest smaller to left

- <https://leetcode.com/problems/online-stock-span/>
