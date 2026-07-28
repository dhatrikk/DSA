# #73 — Set Matrix Zeroes

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 29 July 2026 at 03:42 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 20.8 MB *(beats 51.7%)* |
| **Topics** | `Array` `Hash Table` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/set-matrix-zeroes/)

---

## 📋 Problem Description

Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it in place.

 

**Example 1:**

```
**Input:** matrix = [[1,1,1],[1,0,1],[1,1,1]]
**Output:** [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

```
**Input:** matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
**Output:** [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

 

**Constraints:**

	- `m == matrix.length`

	- `n == matrix[0].length`

	- `1 <= m, n <= 200`

	- `-2^31 <= matrix[i][j] <= 2^31 - 1`

 

**Follow up:**

	- A straightforward solution using `O(mn)` space is probably a bad idea.

	- A simple improvement uses `O(m + n)` space, but still not the best solution.

	- Could you devise a constant space solution?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();

        bool fr=false, fc=false;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(i==0 && matrix[i][j]==0){
                    fr=true;
                }
                if(j==0 && matrix[i][j]==0){
                    fc=true;
                }
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<r;i++){
            if(matrix[i][0]==0){
                for(int j=1;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=1;i<c;i++){
            if(matrix[0][i]==0){
                for(int j=1;j<r;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(fr){
            for(int i=1;i<c;i++){
                matrix[0][i]=0;
            }
        }
        if(fc){
            for(int i=1;i<r;i++){
                matrix[i][0]=0;
            }
        }
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** If any cell of the matrix has a zero we can record its row and column number using additional memory.
But if you don't want to use extra memory then you can manipulate the array instead. i.e. simulating exactly what the question says.

**Hint 2:** Setting cell values to zero on the fly while iterating might lead to discrepancies. What if you use some other integer value as your marker?
There is still a better approach for this problem with O(1) space.

**Hint 3:** We could have used 2 sets to keep a record of rows/columns which need to be set to zero. But for an O(1) space solution, you can use one of the rows and and one of the columns to keep track of this information.

**Hint 4:** We can use the first cell of every row and column as a flag. This flag would determine whether a row or column has been set to zero.

</details>
