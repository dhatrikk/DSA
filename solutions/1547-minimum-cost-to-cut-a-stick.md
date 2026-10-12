# #1547 — Minimum Cost to Cut a Stick

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 12 October 2026 at 06:41 am IST |
| **Runtime** | 15 ms *(beats 93.6%)* |
| **Memory** | 13.6 MB *(beats 92.4%)* |
| **Topics** | `Array` `Dynamic Programming` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-cost-to-cut-a-stick/)

---

## 📋 Problem Description

Given a wooden stick of length `n` units. The stick is labelled from `0` to `n`. For example, a stick of length **6** is labelled as follows:

Given an integer array `cuts` where `cuts[i]` denotes a position you should perform a cut at.

You should perform the cuts in order, you can change the order of the cuts as you wish.

The cost of one cut is the length of the stick to be cut, the total cost is the sum of costs of all cuts. When you cut a stick, it will be split into two smaller sticks (i.e. the sum of their lengths is the length of the stick before the cut). Please refer to the first example for a better explanation.

Return *the minimum total cost* of the cuts.

 

**Example 1:**

```
**Input:** n = 7, cuts = [1,3,4,5]
**Output:** 16
**Explanation:** Using cuts order = [1, 3, 4, 5] as in the input leads to the following scenario:

The first cut is done to a rod of length 7 so the cost is 7. The second cut is done to a rod of length 6 (i.e. the second part of the first cut), the third is done to a rod of length 4 and the last cut is to a rod of length 3. The total cost is 7 + 6 + 4 + 3 = 20.
Rearranging the cuts to be [3, 5, 1, 4] for example will lead to a scenario with total cost = 16 (as shown in the example photo 7 + 4 + 3 + 2 = 16).
```

**Example 2:**

```
**Input:** n = 9, cuts = [5,6,1,4,2]
**Output:** 22
**Explanation:** If you try the given cuts ordering the cost will be 25.
There are much ordering with total cost <= 25, for example, the order [4, 6, 5, 2, 1] has total cost = 22 which is the minimum possible.
```

 

**Constraints:**

	- `2 <= n <= 10^6`

	- `1 <= cuts.length <= min(n - 1, 100)`

	- `1 <= cuts[i] <= n - 1`

	- All the integers in `cuts` array are **distinct**.

---

## ✅ Accepted Solution

```cpp
// Tabulation
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        int s=cuts.size();
        vector<vector<int>> dp(s, vector<int> (s, 0));

        for(int i=s-1;i>=0;i--){
            for(int j=i+1;j<s;j++){
                int cost=1e9;
                for(int c=i+1;c<j;c++){
                    cost=min(cost, cuts[j]-cuts[i]+dp[i][c]+dp[c][j]);
                }
                if(cost==1e9){
                    cost=0;
                }
                dp[i][j]=cost;
            }
        }
        return dp[0][s-1];
    }
};




// Recursion
// class Solution {
//     int f(vector<int>& cuts, int l, int r, vector<vector<int>>& dp){
//         if(l>=r){
//             return 0;
//         }
//         if(dp[l][r]!=-1){
//             return dp[l][r];
//         }
//         int cost=1e9;
//         for(int c=l+1; c<r;c++){
//             cost = min(cost, f(cuts, l, c, dp) + f(cuts, c, r, dp) + cuts[r]-cuts[l]);
//         }
//         if(cost==1e9){
//             return dp[l][r]=0;
//         }
//         return dp[l][r]=cost;
//     }
    
// public:
//     int minCost(int n, vector<int>& cuts) {
//         cuts.push_back(0);
//         cuts.push_back(n);
//         int s=cuts.size();
//         sort(cuts.begin(), cuts.end());
//         vector<vector<int>> dp(s, vector<int> (s, -1));
//         return f(cuts, 0, s-1, dp);
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Build a dp array where dp[i][j] is the minimum cost to achieve all the cuts between i and j.

**Hint 2:** When you try to get the minimum cost between i and j, try all possible cuts k between them, dp[i][j] = min(dp[i][k] + dp[k][j]) + (j - i) for all possible cuts k between them.

</details>
