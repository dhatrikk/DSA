# #2685 — Count the Number of Complete Components

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 12 July 2026 at 10:58 pm IST |
| **Runtime** | 97 ms *(beats 9.8%)* |
| **Memory** | 138.2 MB *(beats 24.0%)* |
| **Topics** | `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` |

🔗 [View on LeetCode](https://leetcode.com/problems/count-the-number-of-complete-components/)

---

## 📋 Problem Description

You are given an integer `n`. There is an **undirected** graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [a_i, b_i]` denotes that there exists an **undirected** edge connecting vertices `a_i` and `b_i`.

Return *the number of **complete connected components** of the graph*.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.

 

**Example 1:**

****

```
**Input:** n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
**Output:** 3
**Explanation:** From the picture above, one can see that all of the components of this graph are complete.
```

**Example 2:**

****

```
**Input:** n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]
**Output:** 1
**Explanation:** The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.
```

 

**Constraints:**

	- `1 <= n <= 50`

	- `0 <= edges.length <= n * (n - 1) / 2`

	- `edges[i].length == 2`

	- `0 <= a_i, b_i <= n - 1`

	- `a_i != b_i`

	- There are no repeated edges.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0);
        vector<vector<int>> adj(n);

        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans=0;
        int v, e, node;
        queue<int> q;

        for(int i=0;i<n;i++){
            if(!visited[i]){
                v=0; 
                e=0;
                q.push(i);
                visited[i]=1;
                v++;
                while(!q.empty()){
                    node=q.front();
                    q.pop();
                    for(int neigh:adj[node]){
                        if(!visited[neigh]){
                            visited[neigh]=1;
                            q.push(neigh);
                            v++;
                        }
                        e++;
                    }
                }
                v=v*(v-1);
                    if(v==e){
                        ans++;
                    }
            }
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Find the connected components of an undirected graph using depth-first search (DFS) or breadth-first search (BFS).

**Hint 2:** For each connected component, count the number of nodes and edges in the component.

**Hint 3:** A connected component is complete if and only if the number of edges in the component is equal to m*(m-1)/2, where m is the number of nodes in the component.

</details>
