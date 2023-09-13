# Bridges

- to find bridges
- you need a dfs-tree
- in dfs-tree
    - every edge that has no backedge or
      its child nodes don't have a backedge to the to the parent node or above nodes
      is a bridge
    - no backedge is bridge, because we just reached that node with other edges

- so to get these node
- you can assign a entry time to all node, the time when you entered them
- and them you can assign the lowest node they can reach to - low,
  which can be update by iterating all adjacent node and the child node value,
  in the end if an node low value is not less than its reaching value
  then it is connected with the bridge.
