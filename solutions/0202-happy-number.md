# #202 — Happy Number

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 04:22 am IST |
| **Runtime** | 1 ms *(beats 50.9%)* |
| **Memory** | 19.1 MB *(beats 95.9%)* |
| **Topics** | `Hash Table` `Math` `Two Pointers` `Floyd's Cycle Finding Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/happy-number/)

---

## 📋 Problem Description

Write an algorithm to determine if a number `n` is happy.

A **happy number** is a number defined by the following process:

	- Starting with any positive integer, replace the number by the sum of the squares of its digits.

	- Repeat the process until the number equals 1 (where it will stay), or it **loops endlessly in a cycle** which does not include 1.

	- Those numbers for which this process **ends in 1** are happy.

Return `true` *if* `n` *is a happy number, and* `false` *if not*.

 

**Example 1:**

```
**Input:** n = 19
**Output:** true
**Explanation:**
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1
```

**Example 2:**

```
**Input:** n = 2
**Output:** false
```

 

**Constraints:**

	- `1 <= n <= 2^31 - 1`

---

## ✅ Accepted Solution

```python
class Solution:
    def isHappy(self, num: int) -> bool:
        vec=[]

        while 1:
            ans=0
            vec.append(num)
            while num:
                ans= ans+(num%10)**2
                num=num//10
            if ans == 1:
                return True
            elif vec.count(ans):
                return False        
            num=ans  
        return False
```
