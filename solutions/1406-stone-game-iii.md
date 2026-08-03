# #1406 — Stone Game III

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 4 August 2026 at 04:28 am IST |
| **Runtime** | 15 ms *(beats 82.4%)* |
| **Memory** | 136.3 MB *(beats 64.7%)* |
| **Topics** | `Array` `Math` `Dynamic Programming` `Minimax` `Game Theory` `Zero-Sum Game` |

🔗 [View on LeetCode](https://leetcode.com/problems/stone-game-iii/)

---

## 📋 Problem Description

Alice and Bob continue their games with piles of stones. There are several stones **arranged in a row**, and each stone has an associated value which is an integer given in the array `stoneValue`.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take `1`, `2`, or `3` stones from the **first** remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is `0` initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob **play optimally**.

Return `"Alice"`* if Alice will win, *`"Bob"`* if Bob will win, or *`"Tie"`* if they will end the game with the same score*.

 

**Example 1:**

```
**Input:** stoneValue = [1,2,3,7]
**Output:** "Bob"
**Explanation:** Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.
```

**Example 2:**

```
**Input:** stoneValue = [1,2,3,-9]
**Output:** "Alice"
**Explanation:** Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.
```

**Example 3:**

```
**Input:** stoneValue = [1,2,3,6]
**Output:** "Tie"
**Explanation:** Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.
```

 

**Constraints:**

	- `1 <= stoneValue.length <= 5 * 10^4`

	- `-1000 <= stoneValue[i] <= 1000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+4, 0);
        int a, b, c;
        int sum=0;

        for(int i=n-1;i>=0;i--){
            sum+=nums[i];
            int a=INT_MIN, b=INT_MIN, c=INT_MIN;
            a=nums[i] + min(dp[i+2], min(dp[i+3], dp[i+4]));
            if(i+1<n){
                b=nums[i] + nums[i+1] + min(dp[i+5], min(dp[i+3], dp[i+4]));
            }
            if(i+2<n){
                c=nums[i] + nums[i+1] + nums[i+2] + min(dp[i+5], min(dp[i+6], dp[i+4]));
            }
            dp[i]=max(a, max(b,c));
        }
        sum-=dp[0];

        if(dp[0]>sum){
            return "Alice";
        }else if(dp[0]==sum){
            return "Tie";
        }
        return "Bob";
    }
};




// class Solution {
//     int f(vector<int>& nums, int i, int n, vector<int>& dp){
//         if(i>=n){
//             return 0;
//         }

//         if(dp[i]!=-1){
//             return dp[i];
//         }

//         int a=INT_MIN, b=INT_MIN, c=INT_MIN;
//         a= nums[i] + min(f(nums, i+2, n, dp), min(f(nums, i+3, n, dp), f(nums, i+4, n, dp)));
        
//         if(i+1<n){
//             b= nums[i] + nums[i+1] + min(f(nums, i+5, n, dp), min(f(nums, i+3, n, dp), f(nums, i+4, n, dp)));
//         }

//         if(i+2<n){
//             c= nums[i] + nums[i+1] + nums[i+2] + min(f(nums, i+5, n, dp), min(f(nums, i+6, n, dp), f(nums, i+4, n, dp)));
//         }

//         return dp[i] = max(a,max(b,c));
        
//     }
// public:
//     string stoneGameIII(vector<int>& nums) {
//         int n= nums.size();
//         int a = 0;
//         int b = 0;
//         for(int i:nums){
//             b+=i;
//         }
//         vector<int> dp(n, -1);
//         a=f(nums, 0, n, dp);
//         b-=a;

//         if(a>b){
//             return "Alice";
//         }
//         if(a==b){
//             return "Tie";
//         }
//         return "Bob";
        
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** The game can be mapped to minmax game. Alice tries to maximize the total score and Bob tries to minimize it.

**Hint 2:** Use dynamic programming to simulate the game. If the total score was 0 the game is "Tie", and if it has positive value then "Alice" wins, otherwise "Bob" wins.

</details>
