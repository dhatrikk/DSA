# #200 — Number of Islands

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 21 September 2026 at 04:04 pm IST |
| **Runtime** | 44 ms *(beats 9.4%)* |
| **Memory** | 19.7 MB *(beats 33.6%)* |
| **Topics** | `Array` `Depth-First Search` `Breadth-First Search` `Union-Find` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/number-of-islands/)

---

## 📋 Problem Description

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return *the number of islands*.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

**Example 1:**

```
**Input:** grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
**Output:** 1
```

**Example 2:**

```
**Input:** grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
**Output:** 3
```

 

**Constraints:**

	- `m == grid.length`

	- `n == grid[i].length`

	- `1 <= m, n <= 300`

	- `grid[i][j]` is `'0'` or `'1'`.

---

## ✅ Accepted Solution

```cpp
class Solution {
    void dfs(vector<vector<char>>& grid, int x, int y, int r, int c){
        vector<int> dx={1,-1,0,0};
        grid[x][y]='0';
        int xx,yy;
        for(int i=0;i<4;i++){
            xx=x+dx[3-i];
            yy=y+dx[i];
            if(xx<r && xx>=0 && yy<c && yy>=0 && grid[xx][yy]=='1'){
                dfs(grid, xx, yy, r, c);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size(), c=grid[0].size();
        int cnt=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    cnt++;
                    dfs(grid, i, j, r, c);
                }
            }
        }
        return cnt;
    }
};
```
