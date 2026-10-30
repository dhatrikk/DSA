# #242 — Valid Anagram

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 05:00 am IST |
| **Runtime** | 10 ms *(beats 80.7%)* |
| **Memory** | 19.3 MB *(beats 93.1%)* |
| **Topics** | `Hash Table` `String` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/valid-anagram/)

---

## 📋 Problem Description

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

 

**Example 1:**

**Input:** s = "anagram", t = "nagaram"

**Output:** true

**Example 2:**

**Input:** s = "rat", t = "car"

**Output:** false

 

**Constraints:**

	- `1 <= s.length, t.length <= 5 * 10^4`

	- `s` and `t` consist of lowercase English letters.

 

**Follow up:** What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

---

## ✅ Accepted Solution

```python
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if len(s) != len(t):
            return False

        a = [0]*26
        b = [0]*26

        for i in range(0, len(s), 1):
            a[ord(s[i])-ord('a')]+=1
            b[ord(t[i])-ord('a')]+=1
        
        if a==b:
            return True

        return False
```
