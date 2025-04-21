# Java Programming

## arrays

- `[index]` - get/set at index
- `.length` - get the size of array
- `int[] arr = new int[size]` - create array of size `size`

## `ArrayList`

- `add(value)` - add value to end
- `add(index, value)` - add value at index
- `remove(index)` - remove value at index
- `remove(value)` - remove `value` from list
- `clear()` - remove all elements
- `get(index)` - get item at index
- `set(index, value)` - set value for given index
- `size()` - size of list
- `isEmpty()` - check if list is empty
- `contains(value)` - check if value is present
- `indexOf(value)` - get the index of value
- `lastIndexOf(value)`- get the last index of value
- `removeIf(lambda: condition)` - remove elements which does not match the condition

## `HashMap` (ordering not preserved)

- `put(key, value)` - insert key value pait in hashmap
- `get(key)` - get value for given key
- `remove(key)`- remove key value pair from map
- `containsKey(key)` - check if key is present in hashmap
- `containsValue(value)` - check if value exists in hashmap
- `size()` - give the size of map
- `isEmpty()` - check if map is empty
- `map.keySet()` - get list of keys
- `map.values()` - get list of values
- `map.entrySet()` - get list of map entries
    - `entry.getKey()` `entry.getValue()`
- `getOrDefault(key, defaultValue)` - get key value, if not present return defaultValue

## `HashSet`

- `add(value)`
- `remove(value)`
- `contains(value)`
- `isEmpty()`
- `size()`
- `clear()`

## `Stack`

- `push(value)`
- `pop()` - removes and returns items
- `top()` - returns top value
- `isEmpty()`
- `size()`

## `Queue`, `LinkedList`, `ArrayDeque`

- `add(item)` - add element to tail
- `remove()` - remove head element and return
- `peek()` - return head element
- `isEmpty()`
- `size()`
- `contains()`
- `clear()`

## `PriorityQueue`

- `add(item)` - add item to priority queue
- `poll()` - remove and return the highest element
- `peek()` - return the highest element
- `remove(item)` - remove item from the priority queue
- `contains(item)`
- `size()`
- `clear()`
- custom comparator

    ```java
    class PersonAgeComparator implements Comparator<Person> { 
        public int compare(Person p1, Person p2) {
            return Integer.compare(p1.age, p2.age);
        }
    }
    Comparator<Person> byAge = new PersonAgeComparator();
    ```

## Short summary

- `HashSet` - implemented using hashing
- `LinkedHashSet` - same as `HashSet` but it maintains insertion order
- `TreeSet` - implemented using a binary search tree(Red black trees), so it can be used to access items in order
- `ArrayList` - like dynamic arrays
- `Vector` - like array list but synchronize, (legacy)
- `LinkedList` - a simple double linked list
- `PriorityQueue` - implemented using heap
- `HashMap` - implemented using hashing
- `LinkedHashMap` - same as `HashMap` but it maintains insertion order
- `TreeMap` - implemented using binary search tree, so items can be accessed in order
