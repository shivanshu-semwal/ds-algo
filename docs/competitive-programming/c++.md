# C++ Programming

## string

- `.length()` `size()` - return the length
- `[]` - get/set value of string
- `.reserve(size)` - reserve size for the string
- `+=` - append
- `append(string)` - append another string
- `insert(index, string)` - insert string at index
- `substr(start, size)` - get a substring of size from start index
- `std::to_string(int)` - integer to string
- `stoi(string)` - string to integer
- `stof(string)` - string to float

## arrays, raw arrays

- `[]` - get/set value at a index
- `sizeof(arr)/sizeof(arr[0])` - get size of arr
- can be of only fixed size, `int arr[SIZE]`
- for variable size use pointers, `int *arr = new int[n]; delete[] arr;`
- fill array with a particular value, `memset(arr, 0, sizeof(arr));`

## `vector`

- `push_back(value)` - add value to end of vector
- `[index]` - get/set value at index
- `size()` - return the size of vector

## `unordered_map` and `map`

- `[index]` - get/set value for a key
- `find(key)` - find if key is present in map, return `map.end()` iterator if not present
- `erase(key)` - remove element from the map
- `clear()` - remove all elements
- `size()` - return total elements in the map

## `unordered_set` and `set`

- `insert(value)` - insert value in set
- `erase(value)` - erase value from set
- `find(value)` - find value in set, if not present return `set.end()`
- `contains(value)` - return `true` if value exists
- `size()` - return total elements in the set

## `stack`

- `push(value)` - push values in the stack
- `pop()` - remove top element from the stack
- `top()` - return top element form the stack
- `empty()` - return `true` if stack is empty
- `size()` - return number of total elements in the stack

## `queue`

- `push(value)` - push value at back of queue
- `pop()` - remove value from front of queue
- `front()` - return the element at front of queue
- `back()` - return the element at end of queue
- `empty()` - return if queue is empty
- `size()` - return the size of the queue

## `priority_queue`

- how to create for pq for particular `type`
    - `priority_queue<type, vector<type>, TypeComparator>`
    - `struct TypeComparator {bool operator()(type a, type b) {return a > b; // custom logic }};`
- by default max heap is there
    - for min heap `priority_queue<int, vector<int>, greater<int>> min_heap;`
- `push(value)` - push value and maintain in heap
- `pop()` - remove the largest value(depending upon how you created) form the heap
- `top()` - return the top element
- `empty()` - check if heap is empty
- `size()` - return the number of elements

## `deque` - double ended queue

- `push_front(value)` - insert value at front
- `push_back(value)` - insert value at back
- `pop_front()`
- `pop_back()`
- `front()`
- `back()`
- `size()`

## `bitset`

- `bitset<SIZE> bit(value)` - create bitset of size with value
- `[index]` - get bit value at index
- `set(index)` - set bit at index, i.e. set to 1
- `reset(index)` - unset bit at index, i.e. set to 0
- `flip(index)` - flip the bit at index
- `count()` - return the number of bit set to 1
- `any()` - check if any bit is set
- `none()` - check if no bit is set
- `test(index)` - check if bit at index is set

## `list` - double linked list

- `size()`

## `unordered_multimap` `multimap`

- can contains same multiple items
