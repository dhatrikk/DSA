# #518 — Coin Change II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 30 September 2026 at 10:55 am IST |
| **Runtime** | 39 ms *(beats 36.7%)* |
| **Memory** | 36.4 MB *(beats 65.4%)* |
| **Topics** | `Array` `Dynamic Programming` `Knapsack Problem` `Complete Knapsack` |

🔗 [View on LeetCode](https://leetcode.com/problems/coin-change-ii/)

---

## 📋 Problem Description

You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.

Return *the number of combinations that make up that amount*. If that amount of money cannot be made up by any combination of the coins, return `0`.

You may assume that you have an infinite number of each kind of coin.

The **final** answer is **guaranteed** to fit into a signed **32-bit** integer.

 

**Example 1:**

```
**Input:** amount = 5, coins = [1,2,5]
**Output:** 4
**Explanation:** there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
```

**Example 2:**

```
**Input:** amount = 3, coins = [2]
**Output:** 0
**Explanation:** the amount of 3 cannot be made up just with coins of 2.
```

**Example 3:**

```
**Input:** amount = 10, coins = [10]
**Output:** 1
```

 

**Constraints:**

	- `1 <= coins.length <= 300`

	- `1 <= coins[i] <= 5000`

	- All the values of `coins` are **unique**.

	- `0 <= amount <= 5000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

        for(int i=1;i<=n;i++){
            for(int s=0;s<=amount;s++){
                if(s==0){
                    dp[i][s]=1;
                    continue;
                }
                if(s>=coins[i-1] && dp[i][s-coins[i-1]]<INT_MAX-dp[i-1][s]){
                    dp[i][s]=dp[i-1][s]+dp[i][s-coins[i-1]];
                }else{
                    dp[i][s]=dp[i-1][s];
                }
            }
        }
        return dp[n][amount];
    }
};




// class Solution {
//     int f(vector<int>& nums, int target, int n, vector<vector<int>>& dp){
//         if(target==0){
//             return 1;
//         }
//         if(n<0 || target<0){
//             return 0;
//         }
//         if(dp[n][target]!=-1){
//             return dp[n][target];
//         }
        
//         return dp[n][target]=f(nums, target-nums[n], n, dp)+f(nums, target, n-1, dp);
//     }
// public:
//     int change(int amount, vector<int>& coins) {
//         int n=coins.size();
//         vector<vector<int>> dp(n, vector<int> (amount+1, -1));
//         return f(coins, amount, n-1, dp);
//     }
// };
```
