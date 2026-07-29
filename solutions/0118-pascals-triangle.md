# #118 — Pascal's Triangle

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 29 July 2026 at 11:18 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 9.9 MB *(beats 9.4%)* |
| **Topics** | `Array` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/pascals-triangle/)

---

## 📋 Problem Description

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown:

 

**Example 1:**

```
**Input:** numRows = 5
**Output:** [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```
**Example 2:**

```
**Input:** numRows = 1
**Output:** [[1]]
```

 

**Constraints:**

	- `1 <= numRows <= 30`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans(n);
        ans[0].push_back({1});

        for (int i = 1; i < n; i++) {
            ans[i].push_back(1);
            for (int j = 1; j < i; j++) {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j - 1]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};
```
