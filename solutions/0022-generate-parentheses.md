# #22 — Generate Parentheses

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 01:50 am IST |
| **Runtime** | 1 ms *(beats 84.2%)* |
| **Memory** | 12.9 MB *(beats 89.0%)* |
| **Topics** | `String` `Dynamic Programming` `Backtracking` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/generate-parentheses/)

---

## 📋 Problem Description

Given `n` pairs of parentheses, write a function to *generate all combinations of well-formed parentheses*.

 

**Example 1:**

```
**Input:** n = 3
**Output:** ["((()))","(()())","(())()","()(())","()()()"]
```
**Example 2:**

```
**Input:** n = 1
**Output:** ["()"]
```

 

**Constraints:**

	- `1 <= n <= 8`

---

## ✅ Accepted Solution

```cpp
class Solution {
    void f(vector<string>& ans, string& s, int o, int c, int n){
        if(o>n){
            return;
        }
        if(c==n && o==n){
            ans.push_back(s);
        }
        if(o>c){
            s+=")";
            f(ans, s, o, c+1, n);
            s.pop_back();
            s+="(";
            f(ans, s, o+1, c, n);
            s.pop_back();
        }
        if(o==c && o<n){
            s+="(";
            f(ans, s, o+1, c, n);
            s.pop_back();
        }

    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        f(ans, s, 0, 0, n);
        return ans;
    }
};
```
