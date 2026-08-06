# #921 — Minimum Add to Make Parentheses Valid

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 7 August 2026 at 04:27 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.3 MB *(beats 96.5%)* |
| **Topics** | `String` `Stack` `Greedy` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

---

## 📋 Problem Description

A parentheses string is valid if and only if:

	- It is the empty string,

	- It can be written as `AB` (`A` concatenated with `B`), where `A` and `B` are valid strings, or

	- It can be written as `(A)`, where `A` is a valid string.

You are given a parentheses string `s`. In one move, you can insert a parenthesis at any position of the string.

	- For example, if `s = "()))"`, you can insert an opening parenthesis to be `"(()))"` or a closing parenthesis to be `"())))"`.

Return *the minimum number of moves required to make *`s`* valid*.

 

**Example 1:**

```
**Input:** s = "())"
**Output:** 1
```

**Example 2:**

```
**Input:** s = "((("
**Output:** 3
```

 

**Constraints:**

	- `1 <= s.length <= 1000`

	- `s[i]` is either `'('` or `')'`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt=0;
        int ans=0;

        for(char c:s){
            if(c=='('){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt<0){
                cnt++;
                ans++;
            }
        }
        return ans+cnt;
    }
};
```
