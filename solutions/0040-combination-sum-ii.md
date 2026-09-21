# #40 — Combination Sum II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 04:34 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14 MB *(beats 63.4%)* |
| **Topics** | `Array` `Backtracking` |

🔗 [View on LeetCode](https://leetcode.com/problems/combination-sum-ii/)

---

## 📋 Problem Description

Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sum to `target`.

Each number in `candidates` may only be used **once** in the combination.

**Note:** The solution set must not contain duplicate combinations.

 

**Example 1:**

```
**Input:** candidates = [10,1,2,7,6,1,5], target = 8
**Output:** 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
```

**Example 2:**

```
**Input:** candidates = [2,5,2,1,2], target = 5
**Output:** 
[
[1,2,2],
[5]
]
```

 

**Constraints:**

	- `1 <= candidates.length <= 100`

	- `1 <= candidates[i] <= 50`

	- `1 <= target <= 30`

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
        f(nums, ans, curr, sum+nums[i], i+1, t);
        curr.pop_back();
        i++;
        while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
        }
        f(nums, ans, curr, sum, i, t);   
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end());
        f(candidates, ans, curr, 0, 0, target);

        return ans;
    }
};
```
