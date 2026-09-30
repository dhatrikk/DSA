# #1049 — Last Stone Weight II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 30 September 2026 at 06:13 am IST |
| **Runtime** | 2 ms *(beats 55.0%)* |
| **Memory** | 12.3 MB *(beats 48.5%)* |
| **Topics** | `Array` `Dynamic Programming` `Knapsack Problem` `0-1 Knapsack` |

🔗 [View on LeetCode](https://leetcode.com/problems/last-stone-weight-ii/)

---

## 📋 Problem Description

You are given an array of integers `stones` where `stones[i]` is the weight of the `i^th` stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights `x` and `y` with `x <= y`. The result of this smash is:

	- If `x == y`, both stones are destroyed, and

	- If `x != y`, the stone of weight `x` is destroyed, and the stone of weight `y` has new weight `y - x`.

At the end of the game, there is **at most one** stone left.

Return *the smallest possible weight of the left stone*. If there are no stones left, return `0`.

 

**Example 1:**

```
**Input:** stones = [2,7,4,1,8,1]
**Output:** 1
**Explanation:**
We can combine 2 and 4 to get 2, so the array converts to [2,7,1,8,1] then,
we can combine 7 and 8 to get 1, so the array converts to [2,1,1,1] then,
we can combine 2 and 1 to get 1, so the array converts to [1,1,1] then,
we can combine 1 and 1 to get 0, so the array converts to [1], then that's the optimal value.
```

**Example 2:**

```
**Input:** stones = [31,26,33,21,40]
**Output:** 5
```

 

**Constraints:**

	- `1 <= stones.length <= 30`

	- `1 <= stones[i] <= 100`

---

## ✅ Accepted Solution

```cpp
class Solution {
    int f(vector<int>& nums, int n, int target, vector<vector<int>>& dp){
        if(n<0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        int take=0;
        if(target>=nums[n]){
            take=nums[n]+f(nums, n-1, target-nums[n], dp);
        }
        int notake= f(nums, n-1, target, dp);
        return dp[n][target]=max(take, notake);
    }

public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum=0, n=stones.size();
        for(int i:stones){
            sum+=i;
        }
        int tot=sum; 
        sum/=2;
        vector<vector<int>> dp(n, vector<int> (sum+1,-1));
        f(stones, n-1, sum, dp);
        return tot-2*dp[n-1][sum];
    }
};



// class Solution {

// public:
//     int lastStoneWeightII(vector<int>& stones) {
//         int sum=0, n=stones.size();
//         for(int i:stones){
//             sum+=i;
//         }
//         int tot=sum; 
//         sum/=2;
//         vector<vector<int>> dp(n+1, vector<int> (sum+1,0));

//         for(int i=1;i<=n;i++){
//             for(int j=0;j<=sum;j++){
//                 dp[i][j]=dp[i-1][j];
//                 if(j>=stones[i-1]){
//                     dp[i][j]=max(dp[i-1][j], stones[i-1]+dp[i-1][j-stones[i-1]]);
//                 }
//             }
//         }
//         return tot-2*dp[n][sum];
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think of the final answer as a sum of weights with + or - sign symbols infront of each weight.  Actually, all sums with 1 of each sign symbol are possible.

**Hint 2:** Use dynamic programming: for every possible sum with N stones, those sums +x or -x is possible with N+1 stones, where x is the value of the newest stone.  (This overcounts sums that are all positive or all negative, but those don't matter.)

</details>
