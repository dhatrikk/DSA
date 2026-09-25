# #678 — Valid Parenthesis String

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 25 September 2026 at 07:48 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8 MB *(beats 93.1%)* |
| **Topics** | `String` `Dynamic Programming` `Stack` `Greedy` `Bracket Sequences` |

🔗 [View on LeetCode](https://leetcode.com/problems/valid-parenthesis-string/)

---

## 📋 Problem Description

Given a string `s` containing only three types of characters: `'('`, `')'` and `'*'`, return `true` *if* `s` *is **valid***.

The following rules define a **valid** string:

	- Any left parenthesis `'('` must have a corresponding right parenthesis `')'`.

	- Any right parenthesis `')'` must have a corresponding left parenthesis `'('`.

	- Left parenthesis `'('` must go before the corresponding right parenthesis `')'`.

	- `'*'` could be treated as a single right parenthesis `')'` or a single left parenthesis `'('` or an empty string `""`.

 

**Example 1:**

```
**Input:** s = "()"
**Output:** true
```

**Example 2:**

```
**Input:** s = "(*)"
**Output:** true
```

**Example 3:**

```
**Input:** s = "(*))"
**Output:** true
```

**Example 4:**

```
**Input:** s = "("
**Output:** false
```

 

**Constraints:**

	- `1 <= s.length <= 100`

	- `s[i]` is `'('`, `')'` or `'*'`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    bool checkValidString(string ss) {
        int n=ss.size();
        int o=0, s=0;

        for(int i=0;i<n;i++){
            if(ss[i]=='('){
                o++;
            }else if(ss[i]==')'){
                o--;
                if(o<0){
                    if(s>0){
                        s--;
                        o++;
                    }else{
                        return false;
                    }
                }
            }else{
                s++;
            }
        }
        if(s<o){
            return false;
        }

        o=0, s=0;
        for(int i=n-1;i>=0;i--){
            if(ss[i]==')'){
                o++;
            }else if(ss[i]=='('){
                o--;
                if(o<0){
                    if(s>0){
                        s--;
                        o++;
                    }else{
                        return false;
                    }
                }
            }else{
                s++;
            }
        }

        if(s<o){
            return false;
        }

        return true;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use backtracking to explore all possible combinations of treating '*' as either '(', ')', or an empty string. If any combination leads to a valid string, return true.

**Hint 2:** DP[i][j] represents whether the substring s[i:j] is valid.

**Hint 3:** Keep track of the count of open parentheses encountered so far. If you encounter a close parenthesis, it should balance with an open parenthesis. Utilize a stack to handle this effectively.

**Hint 4:** How about using 2 stacks instead of 1? Think about it.

</details>
