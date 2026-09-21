# #78 — Subsets

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 01:18 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 15.8 MB *(beats 7.6%)* |
| **Topics** | `Array` `Backtracking` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/subsets/)

---

## 📋 Problem Description

Given an integer array `nums` of **unique** elements, return *all possible* *subsets* *(the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

 

**Example 1:**

```
**Input:** nums = [1,2,3]
**Output:** [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```
**Input:** nums = [0]
**Output:** [[],[0]]
```

 

**Constraints:**

	- `1 <= nums.length <= 10`

	- `-10 <= nums[i] <= 10`

	- All the numbers of `nums` are **unique**.

---

## ✅ Accepted Solution

```cpp
class Solution {
    void f(vector<int>& nums, int i, vector<vector<int>>& ans, int n, vector<int> curr){
        if(i==n){
            ans.push_back(curr);
            return;
        }

        f(nums, i+1, ans, n, curr);
        curr.push_back(nums[i]);
        f(nums, i+1, ans, n, curr);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        f(nums, 0, ans, n, {});
        return ans;
    }
};
```
