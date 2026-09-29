# #494 — Target Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 29 September 2026 at 06:29 am IST |
| **Runtime** | 6 ms *(beats 71.1%)* |
| **Memory** | 12.5 MB *(beats 64.5%)* |
| **Topics** | `Array` `Dynamic Programming` `Backtracking` `Knapsack Problem` `0-1 Knapsack` |

🔗 [View on LeetCode](https://leetcode.com/problems/target-sum/)

---

## 📋 Problem Description

You are given an integer array `nums` and an integer `target`.

You want to build an **expression** out of nums by adding one of the symbols `'+'` and `'-'` before each integer in nums and then concatenate all the integers.

	- For example, if `nums = [2, 1]`, you can add a `'+'` before `2` and a `'-'` before `1` and concatenate them to build the expression `"+2-1"`.

Return the number of different **expressions** that you can build, which evaluates to `target`.

 

**Example 1:**

```
**Input:** nums = [1,1,1,1,1], target = 3
**Output:** 5
**Explanation:** There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3
```

**Example 2:**

```
**Input:** nums = [1], target = 1
**Output:** 1
```

 

**Constraints:**

	- `1 <= nums.length <= 20`

	- `0 <= nums[i] <= 1000`

	- `0 <= sum(nums[i]) <= 1000`

	- `-1000 <= target <= 1000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(abs(target)>sum){
            return 0;
        }
        int req=sum+target;
        if(req%2){
            return 0;
        }
        req/=2;
        int n=nums.size();
        vector<int> curr(req+1, 0), nxt(req+1, 0);
        nxt[0]=1;

        for(int i=n-1;i>=0;i--){
            for(int t=0;t<=req;t++){
                if(t-nums[i]>=0){
                    curr[t]= nxt[t-nums[i]] + nxt[t];
                }else{
                    curr[t]= nxt[t];
                }   
            }
            nxt=curr;
        }
        return curr[req];
    }
};


// class Solution {
//     int f(vector<int>& nums, int target, int i, vector<vector<int>>& dp) {
//         if (target < 0) {
//             return 0;
//         }
//         if (i == nums.size()) {
//             if (target == 0) {
//                 return 1;
//             }
//             return 0;
//         }
//         if(dp[i][target]!=-1){
//             return dp[i][target];
//         }
//         return dp[i][target]=f(nums, target - nums[i], i + 1, dp) + f(nums, target, i + 1, dp);
//     }

// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int sum = 0;
//         for (int i : nums) {
//             sum += i;
//         }
//         if (abs(target) > sum) {
//             return 0;
//         }
//         int req = sum + target;
//         if (req % 2) {
//             return 0;
//         }
//         req /= 2;
//         int n=nums.size();
//         vector<vector<int>> dp(n, vector<int> (req+1,-1));
//         return f(nums, req, 0, dp);
//     }
// };
```
