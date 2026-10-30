# #258 — Add Digits

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 03:36 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 19.1 MB *(beats 81.8%)* |
| **Topics** | `Math` `Simulation` `Number Theory` |

🔗 [View on LeetCode](https://leetcode.com/problems/add-digits/)

---

## 📋 Problem Description

Given an integer `num`, repeatedly add all its digits until the result has only one digit, and return it.

 

**Example 1:**

```
**Input:** num = 38
**Output:** 2
**Explanation:** The process is
38 --> 3 + 8 --> 11
11 --> 1 + 1 --> 2 
Since 2 has only one digit, return it.
```

**Example 2:**

```
**Input:** num = 0
**Output:** 0
```

 

**Constraints:**

	- `0 <= num <= 2^31 - 1`

 

**Follow up:** Could you do it without any loop/recursion in `O(1)` runtime?

---

## ✅ Accepted Solution

```python
class Solution:
    def addDigits(self, numm: int) -> int:
        num=numm
        while num>=10:
            ans=0
            org=num
            while org:
                ans=ans+org%10
                org=org//10
            num=ans

        return num
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** A naive implementation of the above process is trivial. Could you come up with other methods?

**Hint 2:** What are all the possible results?

**Hint 3:** How do they occur, periodically or randomly?

**Hint 4:** You may find this Wikipedia article useful.

</details>
