# #1192 — Critical Connections in a Network

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 7 October 2026 at 04:50 pm IST |
| **Runtime** | 222 ms *(beats 25.7%)* |
| **Memory** | 183 MB *(beats 39.5%)* |
| **Topics** | `Depth-First Search` `Graph Theory` `Biconnected Component` `Bridge (Graph)` |

🔗 [View on LeetCode](https://leetcode.com/problems/critical-connections-in-a-network/)

---

## 📋 Problem Description

There are `n` servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [a_i, b_i]` represents a connection between servers `a_i` and `b_i`. Any server can reach other servers directly or indirectly through the network.

A *critical connection* is a connection that, if removed, will make some servers unable to reach some other server.

Return all critical connections in the network in any order.

 

**Example 1:**

```
**Input:** n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
**Output:** [[1,3]]
**Explanation:** [[3,1]] is also accepted.
```

**Example 2:**

```
**Input:** n = 2, connections = [[0,1]]
**Output:** [[0,1]]
```

 

**Constraints:**

	- `2 <= n <= 10^5`

	- `n - 1 <= connections.length <= 10^5`

	- `0 <= a_i, b_i <= n - 1`

	- `a_i != b_i`

	- There are no repeated connections.

---

## ✅ Accepted Solution

```cpp
class Solution {
    int tm=1;
    void dfs(vector<vector<int>>& adj, vector<int>& low,
             vector<int>& time, int node, int par, vector<vector<int>>& ans) {

        time[node] = tm++;
        low[node] = time[node];
        for (auto ngh : adj[node]) {
            if (time[ngh]==0) {
                dfs(adj, low, time, ngh, node, ans);
                low[node] = min(low[node], low[ngh]);
                if (low[ngh] > time[node]) {
                    ans.push_back({node, ngh});
                }
            } else if (time[ngh]!=0 && ngh != par) {
                low[node] = min(low[node], low[ngh]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n,
                                            vector<vector<int>>& connections) {
        vector<int> time(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> adj(n);
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> ans;

        for (int i = 0; i < n; i++) {
            if (time[i]==0) {
                dfs(adj, low, time, i, -1, ans);
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

**Hint 1:** Use Tarjan's algorithm.

</details>
