# Binary Search

```cpp
int binary_search(vector<int> arr, int item){
    int start = 0, end = arr.size() - 1;
    int ans = -1; // -1 means element not found

    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] == item){
            ans = item;
            break;
        }
        else if(arr[mid] < item){
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
```

There is also a recursive way to do binary search.

```cpp
int binary_search(vector<int> arr, int start, int end, int target){
    if(start < end) return -1; // element not found
    int mid = start + (end - start) / 2;
    if(arr[mid] == target) 
        return mid;
    else if(arr[mid] < target) 
        return binary_search(arr, mid + 1, end, target);
    else 
        return binary_search(arr, start, mid - 1, target);
}
```

Here are some question which will use binary search with some modifications

- Divide a sorted array in two parts and then change position of the parts
  do binary search in this array
- Find the lower bound and upper bound of given element
- Given a monotonic increasing function, we have to find a value which will give
  a particular result from the function

## Lower bound of k, element that is greater than and equal to k

```cpp
int lower_bound(vector<int> arr, int target){
    int start = 0, end = arr.size() - 1;
    int ans = arr.size();
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] >= target){
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
```

## Upper bound of k, first element that is greater than k

```cpp
int upper_bound(vector<int> arr, int target){
    int start = 0, end = arr.size() - 1;
    int ans = arr.size();
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(arr[mid] > target){
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return ans;
}
```

## Resources for binary search

- <https://cp-algorithms.com/num_methods/binary_search.html>
- <https://www.techiedelight.com/binary-search-interview-questions>
- <https://usaco.guide/silver/binary-search>
