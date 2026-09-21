# #994 — Rotting Oranges

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 21 September 2026 at 08:18 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 16.8 MB *(beats 68.7%)* |
| **Topics** | `Array` `Breadth-First Search` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/rotting-oranges/)

---

## 📋 Problem Description

You are given an `m x n` `grid` where each cell can have one of three values:

	- `0` representing an empty cell,

	- `1` representing a fresh orange, or

	- `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If *this is impossible, return* `-1`.

 

**Example 1:**

```
**Input:** grid = [[2,1,1],[1,1,0],[0,1,1]]
**Output:** 4
```

**Example 2:**

```
**Input:** grid = [[2,1,1],[0,1,1],[1,0,1]]
**Output:** -1
**Explanation:** The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
```

**Example 3:**

```
**Input:** grid = [[0,2]]
**Output:** 0
**Explanation:** Since there are already no fresh oranges at minute 0, the answer is just 0.
```

 

**Constraints:**

	- `m == grid.length`

	- `n == grid[i].length`

	- `1 <= m, n <= 10`

	- `grid[i][j]` is `0`, `1`, or `2`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int r=grid.size(), c=grid[0].size();
        int fresh=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }

        int x, y, s, xx, yy;
        int cnt=0;
        int dx[] = {1,-1,0,0};

        while(!q.empty() && fresh>0){
            s=q.size();
            for(int k=0;k<s;k++){
                x=q.front().first;
                y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    xx= x+dx[i];
                    yy= y+dx[3-i]; 

                    if(xx>=0 && xx<r && yy>=0 && yy<c && grid[xx][yy]==1){
                        grid[xx][yy]=2;
                        fresh--;
                        q.push({xx,yy});
                    }
                }
            }
            cnt++;
        }

        if(fresh){
            return -1;
        }

        return cnt;
    }
};
```
