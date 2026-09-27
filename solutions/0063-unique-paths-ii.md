# #63 — Unique Paths II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 September 2026 at 10:09 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 11.6 MB *(beats 76.0%)* |
| **Topics** | `Array` `Dynamic Programming` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/unique-paths-ii/)

---

## 📋 Problem Description

You are given an `m x n` integer array `grid`. There is a robot initially located at the **top-left corner** (i.e., `grid[0][0]`). The robot tries to move to the **bottom-right corner** (i.e., `grid[m - 1][n - 1]`). The robot can only move either down or right at any point in time.

An obstacle and space are marked as `1` or `0` respectively in `grid`. A path that the robot takes cannot include **any** square that is an obstacle.

Return *the number of possible unique paths that the robot can take to reach the bottom-right corner*.

The testcases are generated so that the answer will be less than or equal to `2 * 10^9`.

 

**Example 1:**

```
**Input:** obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
**Output:** 2
**Explanation:** There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:**

```
**Input:** obstacleGrid = [[0,1],[0,0]]
**Output:** 1
```

 

**Constraints:**

	- `m == obstacleGrid.length`

	- `n == obstacleGrid[i].length`

	- `1 <= m, n <= 100`

	- `obstacleGrid[i][j]` is `0` or `1`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();

        vector<int> curr(c, 0);
        curr[0]=1;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    curr[j]=0;
                }else{
                    if(j>0){
                        curr[j]=curr[j]+curr[j-1];
                    }else{
                        curr[j]=curr[j];
                    }
                }
            }
        }

        return curr[c-1];
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use dynamic programming since, from each cell, you can move to the right or down.

**Hint 2:** assume dp[i][j] is the number of unique paths to reach (i, j). dp[i][j] = dp[i][j -1] + dp[i - 1][j]. Be careful when you encounter an obstacle. set its value in dp to 0.

</details>
