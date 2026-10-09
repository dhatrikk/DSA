# #1319 — Number of Operations to Make Network Connected

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 10 October 2026 at 02:51 am IST |
| **Runtime** | 19 ms *(beats 52.7%)* |
| **Memory** | 46.7 MB *(beats 51.7%)* |
| **Topics** | `Depth-First Search` `Breadth-First Search` `Union-Find` `Graph Theory` |

🔗 [View on LeetCode](https://leetcode.com/problems/number-of-operations-to-make-network-connected/)

---

## 📋 Problem Description

There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` forming a network where `connections[i] = [a_i, b_i]` represents a connection between computers `a_i` and `b_i`. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network `connections`. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return *the minimum number of times you need to do this in order to make all the computers connected*. If it is not possible, return `-1`.

 

**Example 1:**

```
**Input:** n = 4, connections = [[0,1],[0,2],[1,2]]
**Output:** 1
**Explanation:** Remove cable between computer 1 and 2 and place between computers 1 and 3.
```

**Example 2:**

```
**Input:** n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
**Output:** 2
```

**Example 3:**

```
**Input:** n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
**Output:** -1
**Explanation:** There are not enough cables.
```

 

**Constraints:**

	- `1 <= n <= 10^5`

	- `1 <= connections.length <= min(n * (n - 1) / 2, 10^5)`

	- `connections[i].length == 2`

	- `0 <= a_i, b_i < n`

	- `a_i != b_i`

	- There are no repeated connections.

	- No two computers are connected by more than one cable.

---

## ✅ Accepted Solution

```cpp
//DSU
class Solution {
    int ult(int n, vector<int>& rep){
        if(n==rep[n]){
            return n;
        }
        return rep[n] = ult(rep[n], rep);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1){
            return -1;
        }
        vector<int> rep(n);
        vector<int> sz(n,1);
        for(int i=0;i<n;i++){
            rep[i]=i;
        }
        int extra=0;

        for(auto it:connections){
            int pu=ult(it[0], rep), pv=ult(it[1], rep);
            if(rep[pu]==rep[pv]){
                extra++;
            }else{
                if(sz[pu]>sz[pv]){
                    rep[pv]=pu;
                    sz[pu]+=sz[pv];
                }else{
                    rep[pu]=pv;
                    sz[pv]+=sz[pu];
                }
            }
        }
        
        int comp=0;
        for(int i=0;i<n;i++){
            if(rep[i]==i){
                comp++;
            }
        }

        if(extra<comp-1){
            return -1;
        }
        return comp-1;
    }
};



// class Solution {
//     void dfs(vector<vector<int>>& adj, vector<bool>& vis, int node){
//         vis[node]=true;
//         for(auto ngh:adj[node]){
//             if(!vis[ngh]){
//                 dfs(adj, vis, ngh);
//             }
//         }
//         return;
//     }

// public:
//     int makeConnected(int n, vector<vector<int>>& conn) {
//         if(conn.size()<n-1){
//             return -1;
//         }
//         vector<vector<int>> adj(n);
//         for(auto it:conn){
//             adj[it[0]].push_back(it[1]);
//             adj[it[1]].push_back(it[0]);
//         }
//         vector<bool> vis(n, false);
//         int cnt=0;

//         for(int i=0;i<n;i++){
//             if(!vis[i]){
//                 cnt++;
//                 dfs(adj, vis, i);
//             }
//         }

//         return cnt-1;

//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** As long as there are at least (n - 1) connections, there is definitely a way to connect all computers.

**Hint 2:** Use DFS to determine the number of isolated computer clusters.

</details>
