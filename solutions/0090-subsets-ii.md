# #90 — Subsets II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 01:52 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 10.3 MB *(beats 84.7%)* |
| **Topics** | `Array` `Backtracking` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/subsets-ii/)

---

## 📋 Problem Description

Given an integer array `nums` that may contain duplicates, return *all possible* *subsets** (the power set)*.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

 

**Example 1:**

```
**Input:** nums = [1,2,2]
**Output:** [[],[1],[1,2],[1,2,2],[2],[2,2]]
```
**Example 2:**

```
**Input:** nums = [0]
**Output:** [[],[0]]
```

 

**Constraints:**

	- `1 <= nums.length <= 10`

	- `-10 <= nums[i] <= 10`

---

## ✅ Accepted Solution

```cpp
class Solution {
    void f(vector<vector<int>>& ans, vector<int>& nums, vector<int>& curr, int i){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        i++;
        f(ans, nums, curr, i);
        curr.pop_back();
        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }
        f(ans, nums, curr, i);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        vector<int> curr;
        f(ans, nums, curr, 0);
        return ans;
    }
};
```
