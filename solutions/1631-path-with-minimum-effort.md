# #1631 — Path With Minimum Effort

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 3 October 2026 at 02:12 pm IST |
| **Runtime** | 63 ms *(beats 39.9%)* |
| **Memory** | 24.4 MB *(beats 78.2%)* |
| **Topics** | `Array` `Binary Search` `Depth-First Search` `Breadth-First Search` `Union-Find` `Heap (Priority Queue)` `Matrix` `Dijkstra's Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/path-with-minimum-effort/)

---

## 📋 Problem Description

You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`. You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows-1, columns-1)` (i.e., **0-indexed**). You can move **up**, **down**, **left**, or **right**, and you wish to find a route that requires the minimum **effort**.

A route's **effort** is the **maximum absolute difference**** **in heights between two consecutive cells of the route.

Return *the minimum **effort** required to travel from the top-left cell to the bottom-right cell.*

 

**Example 1:**

```
**Input:** heights = [[1,2,2],[3,8,2],[5,3,5]]
**Output:** 2
**Explanation:** The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
```

**Example 2:**

```
**Input:** heights = [[1,2,3],[3,8,4],[5,3,5]]
**Output:** 1
**Explanation:** The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
```

**Example 3:**

```
**Input:** heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
**Output:** 0
**Explanation:** This route does not require any effort.
```

 

**Constraints:**

	- `rows == heights.length`

	- `columns == heights[i].length`

	- `1 <= rows, columns <= 100`

	- `1 <= heights[i][j] <= 10^6`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& ht) {
        int r=ht.size(), c=ht[0].size();
        vector<vector<int>> eff(r, vector<int> (c, INT_MAX));
        eff[0][0]=0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        
        q.push({0,{0,0}});
        int x, y, xx, yy;
        vector<int> dx = {1,-1,0,0};

        while(!q.empty()){
            x=q.top().second.first;
            y=q.top().second.second;
            q.pop();
            for(int i=0;i<4;i++){
                xx=x+dx[i];
                yy=y+dx[3-i];
                if(xx>=0 && yy>=0 && xx<r && yy<c && eff[xx][yy]>max(eff[x][y], abs(ht[x][y]-ht[xx][yy]))){
                        eff[xx][yy]=max(eff[x][y], abs(ht[x][y]-ht[xx][yy]));
                        q.push({eff[xx][yy],{xx,yy}});
                }
            }
        }
        return eff[r-1][c-1];
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Consider the grid as a graph, where adjacent cells have an edge with cost of the difference between the cells.

**Hint 2:** If you are given threshold k, check if it is possible to go from (0, 0) to (n-1, m-1) using only edges of ≤ k cost.

**Hint 3:** Binary search the k value.

</details>
