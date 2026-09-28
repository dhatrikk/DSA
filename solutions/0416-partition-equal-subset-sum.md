# #416 — Partition Equal Subset Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 28 September 2026 at 09:57 pm IST |
| **Runtime** | 75 ms *(beats 84.3%)* |
| **Memory** | 15.7 MB *(beats 73.7%)* |
| **Topics** | `Array` `Dynamic Programming` `Knapsack Problem` `0-1 Knapsack` |

🔗 [View on LeetCode](https://leetcode.com/problems/partition-equal-subset-sum/)

---

## 📋 Problem Description

Given an integer array `nums`, return `true` *if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or *`false`* otherwise*.

 

**Example 1:**

```
**Input:** nums = [1,5,11,5]
**Output:** true
**Explanation:** The array can be partitioned as [1, 5, 5] and [11].
```

**Example 2:**

```
**Input:** nums = [1,2,3,5]
**Output:** false
**Explanation:** The array cannot be partitioned into equal sum subsets.
```

 

**Constraints:**

	- `1 <= nums.length <= 200`

	- `1 <= nums[i] <= 100`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i:nums){
            sum+=i;
        }
        if(sum%2){
            return false;
        }
        sum/=2;
        vector<int> curr(sum+1, 0), prev(sum+1,0);
        if(nums[0]<=sum){
            curr[nums[0]]=1;
        }
        for(int i=1;i<n;i++){
            for(int s=0;s<=sum;s++){
                if(s==0){
                    curr[s]=1;
                }
                if((s-nums[i]>=0 && prev[s-nums[i]]) || prev[s]){
                    curr[s]=1;
                }
            }
            prev=curr;
        }
        return curr[sum];
    }
};


// class Solution {
//     int f(vector<int>& nums, int i,int target, vector<vector<int>>& dp) {
//         if (target == 0) {
//             return 1;
//         }
//         if (i == -1 || target<0) {
//             return 0;
//         }
//         if(dp[i][target]!=-1){
//             return dp[i][target];
//         }
//         if (f(nums, i - 1, target - nums[i], dp) || f(nums, i - 1, target, dp)) {
//             return dp[i][target]=1;
//         }
//         return dp[i][target]=0;
//     }

// public:
//     bool canPartition(vector<int>& nums) {
//         int n = nums.size();
//         int sum = 0;
//         for (int i : nums) {
//             sum += i;
//         }
//         if (sum % 2 == 1) {
//             return false;
//         }
//         sum/=2;
//         vector<vector<int>> dp(n, vector<int> (sum+1, -1));
//         return f(nums, n - 1, sum, dp);
//     }
// };
```
