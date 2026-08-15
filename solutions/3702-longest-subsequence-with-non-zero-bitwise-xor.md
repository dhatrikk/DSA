# #3702 — Longest Subsequence With Non-Zero Bitwise XOR

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 15 August 2026 at 05:46 pm IST |
| **Runtime** | 1 ms *(beats 50.7%)* |
| **Memory** | 171.4 MB *(beats 22.7%)* |
| **Topics** | `Array` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-subsequence-with-non-zero-bitwise-xor/)

---

## 📋 Problem Description

You are given an integer array `nums`.

Return the length of the **longest subsequence** in `nums` whose bitwise **XOR** is **non-zero**. If no such **subsequence** exists, return 0.

 

**Example 1:**

**Input:** nums = [1,2,3]

**Output:** 2

**Explanation:**

One longest subsequence is `[2, 3]`. The bitwise XOR is computed as `2 XOR 3 = 1`, which is non-zero.

**Example 2:**

**Input:** nums = [2,3,4]

**Output:** 3

**Explanation:**

The longest subsequence is `[2, 3, 4]`. The bitwise XOR is computed as `2 XOR 3 XOR 4 = 5`, which is non-zero.

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `0 <= nums[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr=0;
        bool zero=true;
        for(int i:nums){
            xr=xr^i;
            if(zero && i){
                zero=false;
            }
        }
        if(zero){
            return 0;
        }
        int n=nums.size();
        if(xr){
            return n;
        }
        return n-1;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** What happens if you take the entire array?

**Hint 2:** If the XOR of the entire array is 0, can removing one element help?

**Hint 3:** What if all elements are 0?

</details>
