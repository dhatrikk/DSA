# #205 — Isomorphic Strings

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 5 August 2026 at 03:51 pm IST |
| **Runtime** | 3 ms *(beats 40.9%)* |
| **Memory** | 9.1 MB *(beats 98.9%)* |
| **Topics** | `Hash Table` `String` |

🔗 [View on LeetCode](https://leetcode.com/problems/isomorphic-strings/)

---

## 📋 Problem Description

Given two strings `s` and `t`, *determine if they are isomorphic*.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

**Example 1:**

**Input:** s = "egg", t = "add"

**Output:** true

**Explanation:**

The strings `s` and `t` can be made identical by:

	- Mapping `'e'` to `'a'`.

	- Mapping `'g'` to `'d'`.

**Example 2:**

**Input:** s = "f11", t = "b23"

**Output:** false

**Explanation:**

The strings `s` and `t` can not be made identical as `'1'` needs to be mapped to both `'2'` and `'3'`.

**Example 3:**

**Input:** s = "paper", t = "title"

**Output:** true

 

**Constraints:**

	- `1 <= s.length <= 5 * 10^4`

	- `t.length == s.length`

	- `s` and `t` consist of any valid ascii character.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        string inp="", op="";
        for(int i=0;i<n;i++){
            if(inp.find(s[i])==string::npos && op.find(t[i])==string::npos){
                inp+=s[i];
                op+=t[i];
            }else if(inp.find(s[i])!=string::npos){
                if(op[inp.find(s[i])]!=t[i]){
                    return false;
                }
            }else if(op.find(t[i])!=string::npos){
                if(inp[op.find(t[i])]!=s[i]){
                    return false;
                }
            }
        }
        return true;
    }
};
```
