# #787 — Cheapest Flights Within K Stops

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 5 October 2026 at 12:17 pm IST |
| **Runtime** | 9 ms *(beats 20.4%)* |
| **Memory** | 18.3 MB *(beats 42.6%)* |
| **Topics** | `Dynamic Programming` `Depth-First Search` `Breadth-First Search` `Graph Theory` `Heap (Priority Queue)` `Shortest Path` |

🔗 [View on LeetCode](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

---

## 📋 Problem Description

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [from_i, to_i, price_i]` indicates that there is a flight from city `from_i` to city `to_i` with cost `price_i`.

You are also given three integers `src`, `dst`, and `k`, return ***the cheapest price** from *`src`* to *`dst`* with at most *`k`* stops. *If there is no such route, return* *`-1`.

 

**Example 1:**

```
**Input:** n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
**Output:** 700
**Explanation:**
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.
```

**Example 2:**

```
**Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
**Output:** 200
**Explanation:**
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
```

**Example 3:**

```
**Input:** n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
**Output:** 500
**Explanation:**
The graph is shown above.
The optimal path with no stops from city 0 to 2 is marked in red and has cost 500.
```

 

**Constraints:**

	- `2 <= n <= 100`

	- `0 <= flights.length <= (n * (n - 1) / 2)`

	- `flights[i].length == 3`

	- `0 <= from_i, to_i < n`

	- `from_i != to_i`

	- `1 <= price_i <= 10^4`

	- There will not be any multiple flights between two cities.

	- `0 <= src, dst, k < n`

	- `src != dst`

---

## ✅ Accepted Solution

```cpp
// Bellman-Ford
// class Solution {
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
//         vector<int> dis(n, INT_MAX), tmp;
//         dis[src]=0;

//         for(int i=0;i<=k;i++){
//             tmp=dis;
//             for(auto it:flights){
//                 if(tmp[it[0]]!=INT_MAX){
//                     dis[it[1]]=min(dis[it[1]], tmp[it[0]]+it[2]);
//                 }
//             }
//         }

//         return dis[dst]==INT_MAX?-1:dis[dst];
//     }
// };





// BFS
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        k++;
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, src});

        vector<vector<pair<int, int>>> adj(n);
        for (auto it : flights) {
            adj[it[0]].push_back({it[2], it[1]});
        }
        vector<int> dis(n, INT_MAX);
        dis[src] = 0;

        while (!q.empty()) {
            int node = q.front().second;
            int cost = q.front().first.first;
            int stp = q.front().first.second;
            q.pop();

            if (stp == k) {
                continue;
            }

            for (auto neigh : adj[node]) {
                if (dis[neigh.second] > cost + neigh.first && stp <= k) {
                    dis[neigh.second] = cost + neigh.first;
                    q.push({{dis[neigh.second], stp + 1}, neigh.second});
                }
            }
        }

        return dis[dst] == INT_MAX ? -1 : dis[dst];
    }
};







// TLE
// class Solution {
//     void f(vector<vector<pair<int,int>>>& adj, int& ans, int node, int dst,
//     int k, int cost, vector<int>& vis){
//         vis[node]=1;
//         if(node==dst){
//             ans=min(ans, cost);
//             vis[node]=0;
//             return;
//         }
//         if(k==0){
//             vis[node]=0;
//             return;
//         }
//         for(auto neigh:adj[node]){
//             if(vis[neigh.second]==0){
//                 f(adj, ans, neigh.second, dst, k-1, cost+neigh.first, vis);
//             }
//         }
//         vis[node]=0;
//         return;
//     }
// public:
//     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int
//     dst, int k) {
//         vector<vector<pair<int,int>>> adj(n);
//         for(auto it :flights){
//             adj[it[0]].push_back({it[2], it[1]});
//         }
//         vector<int> vis(n,0);
//         int ans=INT_MAX;
//         f(adj, ans, src, dst, k+1, 0, vis);

//         return ans==INT_MAX?-1:ans;
//     }
// };
```
