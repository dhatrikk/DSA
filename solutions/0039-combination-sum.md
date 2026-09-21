# #39 — Combination Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 04:12 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14.1 MB *(beats 57.3%)* |
| **Topics** | `Array` `Backtracking` |

🔗 [View on LeetCode](https://leetcode.com/problems/combination-sum/)

---

## 📋 Problem Description

Given an array of **distinct** integers `candidates` and a target integer `target`, return *a list of all **unique combinations** of *`candidates`* where the chosen numbers sum to *`target`*.* You may return the combinations in **any order**.

The **same** number may be chosen from `candidates` an **unlimited number of times**. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to `target` is less than `150` combinations for the given input.

 

**Example 1:**

```
**Input:** candidates = [2,3,6,7], target = 7
**Output:** [[2,2,3],[7]]
**Explanation:**
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
```

**Example 2:**

```
**Input:** candidates = [2,3,5], target = 8
**Output:** [[2,2,2,2],[2,3,3],[3,5]]
```

**Example 3:**

```
**Input:** candidates = [2], target = 1
**Output:** []
```

 

**Constraints:**

	- `1 <= candidates.length <= 30`

	- `2 <= candidates[i] <= 40`

	- All elements of `candidates` are **distinct**.

	- `1 <= target <= 40`

---

## ✅ Accepted Solution

```cpp
class Solution {
    void f(vector<int>& nums, vector<vector<int>>& ans, vector<int>& curr, int sum, int i, int t){
        if(sum==t){
            ans.push_back(curr);
            return;
        }
        if(sum>t || i==nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        f(nums, ans, curr, sum+nums[i], i, t);
        curr.pop_back();
        f(nums, ans, curr, sum, i+1, t);   
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;

        f(candidates, ans, curr, 0, 0, target);

        return ans;
        
    }
};
```
