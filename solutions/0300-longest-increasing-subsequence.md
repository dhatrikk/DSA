# #300 — Longest Increasing Subsequence

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 30 September 2026 at 09:01 pm IST |
| **Runtime** | 183 ms *(beats 35.8%)* |
| **Memory** | 14.4 MB *(beats 48.0%)* |
| **Topics** | `Array` `Binary Search` `Dynamic Programming` `Longest Increasing Subsequence` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-increasing-subsequence/)

---

## 📋 Problem Description

Given an integer array `nums`, return *the length of the longest **strictly increasing ******subsequence***.

 

**Example 1:**

```
**Input:** nums = [10,9,2,5,3,7,101,18]
**Output:** 4
**Explanation:** The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```
**Input:** nums = [0,1,0,3,2,3]
**Output:** 4
```

**Example 3:**

```
**Input:** nums = [7,7,7,7,7,7,7]
**Output:** 1
```

 

**Constraints:**

	- `1 <= nums.length <= 2500`

	- `-10^4 <= nums[i] <= 10^4`

 

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        int take;

        for(int i=1;i<=n;i++){
            for(int p=n;p>0;p--){
                take=0;
                if(p==n || nums[p]>nums[i-1]){
                    take=1+dp[i-1];
                }
                dp[p]=max(take, dp[p]);
            }
        }
        return dp[n];
    }
};


// class Solution {
//     int f(vector<int>& nums, int n, int p, vector<vector<int>>& dp){
//         if(n<0){
//             return 0;
//         }
//         if(dp[n][p]!=-1){
//             return dp[n][p];
//         }
//         int notake=f(nums, n-1, p, dp);
//         int take=0;
//         if(p==nums.size() || nums[p]>nums[n]){
//             take = 1+f(nums, n-1, n, dp);
//         }
//         return dp[n][p]=max(take, notake);
//     }
// public:
//     int lengthOfLIS(vector<int>& nums) {
//         int n=nums.size();
//         vector<vector<int>> dp(n, vector<int> (n+1,-1));
//         return f(nums, n-1, n, dp);
//     }
// };
```
