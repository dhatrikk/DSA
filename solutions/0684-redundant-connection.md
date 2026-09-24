# #684 — Redundant Connection

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 24 September 2026 at 07:17 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14.7 MB *(beats 19.8%)* |
| **Topics** | `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` |

🔗 [View on LeetCode](https://leetcode.com/problems/redundant-connection/)

---

## 📋 Problem Description

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where `edges[i] = [a_i, b_i]` indicates that there is an edge between nodes `a_i` and `b_i` in the graph.

Return *an edge that can be removed so that the resulting graph is a tree of *`n`* nodes*. If there are multiple answers, return the answer that occurs last in the input.

 

**Example 1:**

```
**Input:** edges = [[1,2],[1,3],[2,3]]
**Output:** [2,3]
```

**Example 2:**

```
**Input:** edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
**Output:** [1,4]
```

 

**Constraints:**

	- `n == edges.length`

	- `3 <= n <= 1000`

	- `edges[i].length == 2`

	- `1 <= a_i < b_i <= edges.length`

	- `a_i != b_i`

	- There are no repeated edges.

	- The given graph is connected.

---

## ✅ Accepted Solution

```cpp
class Solution {
    int f(vector<vector<int>>& adj, vector<int>& vis, int node, int par, int target){
        vis[node]=1;
        if(node==target){
            return 1;
        }
        for(auto ngh:adj[node]){
            if(vis[ngh]==0 && ngh!=par){
                if(f(adj, vis, ngh, node, target)){
                    return 1;
                }
            }
        }
        return 0;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n+1,0);

        for(int i=n-1;i>=0;i--){
            if(f(adj, vis, edges[i][0], edges[i][1], edges[i][1])){
                return edges[i];
            }
            vis.assign(vis.size(), 0);
        }

        return {-1,-1};
    }
};
```
