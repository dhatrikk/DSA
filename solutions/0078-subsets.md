# #78 — Subsets

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 07:11 pm IST |
| **Runtime** | 3 ms *(beats 27.9%)* |
| **Memory** | 9.9 MB *(beats 82.0%)* |
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
//BIT OPERATION
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> tmp;
            for(int j=0;j<n;j++){
                if(1<<j & mask){
                    tmp.push_back(nums[j]);
                }
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};




// class Solution {
//     void f(vector<int>& nums, int i, vector<vector<int>>& ans, int n, vector<int>& curr){
//         if(i==n){
//             ans.push_back(curr);
//             return;
//         }
//         f(nums, i+1, ans, n, curr);
//         curr.push_back(nums[i]);
//         f(nums, i+1, ans, n, curr);
//         curr.pop_back();
//     }
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;
//         int n=nums.size();
//         vector<int> curr;
//         f(nums, 0, ans, n, curr);
//         return ans;
//     }
// };
```
