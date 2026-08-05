# #1614 — Maximum Nesting Depth of the Parentheses

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 5 August 2026 at 04:50 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.3 MB *(beats 86.6%)* |
| **Topics** | `String` `Stack` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

---

## 📋 Problem Description

Given a **valid parentheses string** `s`, return the **nesting depth** of* *`s`. The nesting depth is the **maximum** number of nested parentheses.

 

**Example 1:**

**Input:** s = "(1+(2*3)+((8)/4))+1"

**Output:** 3

**Explanation:**

Digit 8 is inside of 3 nested parentheses in the string.

**Example 2:**

**Input:** s = "(1)+((2))+(((3)))"

**Output:** 3

**Explanation:**

Digit 3 is inside of 3 nested parentheses in the string.

**Example 3:**

**Input:** s = "()(())((()()))"

**Output:** 3

 

**Constraints:**

	- `1 <= s.length <= 100`

	- `s` consists of digits `0-9` and characters `'+'`, `'-'`, `'*'`, `'/'`, `'('`, and `')'`.

	- It is guaranteed that parentheses expression `s` is a VPS.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxDepth(string s) {
        int ans=0;
        int cnt=0;
        for(char c:s){
            if(c=='('){
                cnt++;
                ans=max(ans,cnt);
            }else if(c==')'){
                cnt--;
            }
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** The depth of any character in the VPS is the ( number of left brackets before it ) - ( number of right brackets before it )

</details>
