# #207 — Course Schedule

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 03:44 pm IST |
| **Runtime** | 6 ms *(beats 51.4%)* |
| **Memory** | 20.2 MB *(beats 25.6%)* |
| **Topics** | `Depth-First Search` `Breadth-First Search` `Graph Theory` `Topological Sort` `Directed Acyclic Graph` |

🔗 [View on LeetCode](https://leetcode.com/problems/course-schedule/)

---

## 📋 Problem Description

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [a_i, b_i]` indicates that you **must** take course `b_i` first if you want to take course `a_i`.

	- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

 

**Example 1:**

```
**Input:** numCourses = 2, prerequisites = [[1,0]]
**Output:** true
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```
**Input:** numCourses = 2, prerequisites = [[1,0],[0,1]]
**Output:** false
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
```

 

**Constraints:**

	- `1 <= numCourses <= 2000`

	- `0 <= prerequisites.length <= 5000`

	- `prerequisites[i].length == 2`

	- `0 <= a_i, b_i < numCourses`

	- All the pairs prerequisites[i] are **unique**.

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool f(vector<vector<int>>& adj, int n, vector<int>& vis){
        vis[n]=1;
        for(int neigh:adj[n]){
            if(vis[neigh]==1){
                return false;
            }
            if(vis[neigh]==0){
                if(!f(adj, neigh, vis)){
                    return false;
                }
            }
        }
        vis[n]=2;
        return true;
    }
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);

        for(auto it:pre){
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(!f(adj, i, vis)){
                    return false;
                }
            }
        }
        return true;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.

**Hint 2:** Topological Sort via DFS - A great tutorial explaining the basic concepts of Topological Sort.

**Hint 3:** Topological sort could also be done via BFS.

</details>
