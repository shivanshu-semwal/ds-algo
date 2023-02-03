# dijkstras

so the algorithms is pretty simple

- you have some nodes
- some edges which have some weight assigned to them
- and you have one node for which we have to find
- shortest path to all other edges

- you create two arrays
    - array which contain the shortest distance to that node
    - and the source node through which you will reach this node, this help in reconstruction of path

- now create a set
- assign all the elements the distance inf except source node which is 0
- now repeat these steps till all nodes are not in the set
    - choose the node with smallest distance and which is not in the set
    - add that to the set
    - now check for all adjacent nodes of the picked node
        - if path through node is smaller or not
        - $d(a, b) = \min(d(a, c) + d(c, b))$
        - if yes update distance and source to this node
- now you have shortest distance
