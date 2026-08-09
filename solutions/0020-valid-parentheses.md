# #20 — Valid Parentheses

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 10:16 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.8 MB *(beats 89.8%)* |
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

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c:s){
            if(c==')'){
                if(st.size() && st.top()=='('){
                    st.pop();
                }else{
                    return false;
                }
            }else if(c=='}'){
                if(st.size() && st.top()=='{'){
                    st.pop();
                }else{
                    return false;
                }
            }else if(c==']'){
                if(st.size() && st.top()=='['){
                    st.pop();
                }else{
                    return false;
                }
            }else {
                st.push(c);
            }
        }

        return st.size()?false:true;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use a stack of characters.

**Hint 2:** When you encounter an opening bracket, push it to the top of the stack.

**Hint 3:** When you encounter a closing bracket, check if the top of the stack was the opening for it. If yes, pop it from the stack. Otherwise, return false.

</details>
