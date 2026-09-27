# #714 — Best Time to Buy and Sell Stock with Transaction Fee

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 28 September 2026 at 02:31 am IST |
| **Runtime** | 16 ms *(beats 69.7%)* |
| **Memory** | 63.5 MB *(beats 81.3%)* |
| **Topics** | `Array` `Dynamic Programming` `Greedy` |

🔗 [View on LeetCode](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/)

---

## 📋 Problem Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day, and an integer `fee` representing a transaction fee.

Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.

**Note:**

	- You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

	- The transaction fee is only charged once for each stock purchase and sale.

 

**Example 1:**

```
**Input:** prices = [1,3,2,8,4,9], fee = 2
**Output:** 8
**Explanation:** The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
```

**Example 2:**

```
**Input:** prices = [1,3,7,5,10,3], fee = 3
**Output:** 6
```

 

**Constraints:**

	- `1 <= prices.length <= 5 * 10^4`

	- `1 <= prices[i] < 5 * 10^4`

	- `0 <= fee < 5 * 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<int> dp(2,0), next(2,0);

        for(int i=n-1; i>=0; i--){
            dp[1]=max(prices[i]+next[0], next[1]);
            dp[0]=max(-prices[i]-fee+next[1], next[0]);
            next=dp;
        }
        return dp[0];
    }
};


// class Solution {
//     int f(vector<int>& prices, int fee, int d, int stock, vector<vector<int>>& dp, int n) {
//         if (d == n) {
//             return 0;
//         }
//         if(dp[d][stock]!=-1){
//             return dp[d][stock];
//         }
//         if (!stock) {
//             return dp[d][stock]=max(f(prices, fee, d + 1, 0, dp, n),
//                        -prices[d] + f(prices, fee, d + 1, 1, dp, n)-fee);
//         }
//         return dp[d][stock]=max(prices[d] + f(prices, fee, d + 1, 0, dp, n), f(prices, fee, d+1, 1, dp, n));
//     }

// public:
//     int maxProfit(vector<int>& prices, int fee) {
//         int n=prices.size();
//         vector<vector<int>> dp(n, vector<int> (2,-1));
//         return f(prices, fee, 0, 0, dp, n);
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Consider the first K stock prices.  At the end, the only legal states are that you don't own a share of stock, or that you do.  Calculate the most profit you could have under each of these two cases.

</details>
