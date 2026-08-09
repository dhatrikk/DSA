# #48 — Rotate Image

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 10:56 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.2 MB *(beats 71.2%)* |
| **Topics** | `Array` `Math` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/rotate-image/)

---

## 📋 Problem Description

You are given an `n x n` 2D `matrix` representing an image, rotate the image by **90** degrees (clockwise).

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

 

**Example 1:**

```
**Input:** matrix = [[1,2,3],[4,5,6],[7,8,9]]
**Output:** [[7,4,1],[8,5,2],[9,6,3]]
```

**Example 2:**

```
**Input:** matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
**Output:** [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

 

**Constraints:**

	- `n == matrix.length == matrix[i].length`

	- `1 <= n <= 20`

	- `-1000 <= matrix[i][j] <= 1000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int tmp;

        for (int r = 0; r < n / 2; r++) {
            for (int c = 0; c < (n + 1) / 2; c++) {
                tmp = matrix[r][c];
                matrix[r][c] = matrix[n - 1 - c][r];
                matrix[n - 1 - c][r] = matrix[n - 1 - r][n - 1 - c];
                matrix[n - 1 - r][n - 1 - c] = matrix[c][n - 1 - r];
                matrix[c][n - 1 - r] = tmp;
            }
        }
    }
};


// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         vector<vector<int>> ans(n, vector<int>(n,0));

//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 ans[j][n-1-i]=matrix[i][j];
//             }
//         }
//         matrix=ans;
//     }
// };
```
