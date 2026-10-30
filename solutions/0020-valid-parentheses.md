# #20 — Valid Parentheses

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 05:23 am IST |
| **Runtime** | 1 ms *(beats 46.6%)* |
| **Memory** | 19.2 MB *(beats 86.7%)* |
| **Topics** | `String` `Stack` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/valid-parentheses/)

---

## 📋 Problem Description

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

	1. Open brackets must be closed by the same type of brackets.

	2. Open brackets must be closed in the correct order.

	3. Every close bracket has a corresponding open bracket of the same type.

 

**Example 1:**

**Input:** s = "()"

**Output:** true

**Example 2:**

**Input:** s = "()[]{}"

**Output:** true

**Example 3:**

**Input:** s = "(]"

**Output:** false

**Example 4:**

**Input:** s = "([])"

**Output:** true

**Example 5:**

**Input:** s = "([)]"

**Output:** false

 

**Constraints:**

	- `1 <= s.length <= 10^4`

	- `s` consists of parentheses only `'()[]{}'`.

---

## ✅ Accepted Solution

```python
class Solution:
    def isValid(self, s: str) -> bool:
        
        st = []

        for i in range(0, len(s), 1):
            if len(st) and ((s[i]==')' and st[-1]=='(') or (s[i]==']' and st[-1]=='[') or (s[i]=='}' and st[-1]=='{')):
                st.pop()
            else:
                st.append(s[i])    

        if len(st):
            return False       
        return True
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use a stack of characters.

**Hint 2:** When you encounter an opening bracket, push it to the top of the stack.

**Hint 3:** When you encounter a closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.

</details>
