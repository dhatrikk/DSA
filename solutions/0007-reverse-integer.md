# #7 — Reverse Integer

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 6 July 2026 at 06:38 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.5 MB *(beats 54.5%)* |
| **Topics** | `Math` |

🔗 [View on LeetCode](https://leetcode.com/problems/reverse-integer/)

---

## 📋 Problem Description

Given a signed 32-bit integer `x`, return `x`* with its digits reversed*. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

 

**Example 1:**

```
**Input:** x = 123
**Output:** 321
```

**Example 2:**

```
**Input:** x = -123
**Output:** -321
```

**Example 3:**

```
**Input:** x = 120
**Output:** 21
```

 

**Constraints:**

	- `-2^31 <= x <= 2^31 - 1`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int reverse(int x) {
        bool neg=false;
        int ans=0;
        while(x){
            if(ans>INT_MAX/10 || (ans==INT_MAX/10 && x%10>7)) return 0;
            if(ans<INT_MIN/10 || (ans==INT_MIN/10 && x%10>8)) return 0;
            ans=ans*10;
            ans+=x%10;
            x=x/10;
        }
        return ans;
    }
};
```
