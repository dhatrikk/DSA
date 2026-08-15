# #686 — Repeated String Match

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 15 August 2026 at 05:58 pm IST |
| **Runtime** | 4 ms *(beats 60.7%)* |
| **Memory** | 9.6 MB *(beats 82.6%)* |
| **Topics** | `String` `String Matching` `Z Algorithm` `Knuth–Morris–Pratt Algorithm` `Boyer–Moore String-Search Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/repeated-string-match/)

---

## 📋 Problem Description

Given two strings `a` and `b`, return *the minimum number of times you should repeat string *`a`* so that string* `b` *is a substring of it*. If it is impossible for `b`​​​​​​ to be a substring of `a` after repeating it, return `-1`.

**Notice:** string `"abc"` repeated 0 times is `""`, repeated 1 time is `"abc"` and repeated 2 times is `"abcabc"`.

 

**Example 1:**

```
**Input:** a = "abcd", b = "cdabcdab"
**Output:** 3
**Explanation:** We return 3 because by repeating a three times "ab**cdabcdab**cd", b is a substring of it.
```

**Example 2:**

```
**Input:** a = "a", b = "aa"
**Output:** 2
```

 

**Constraints:**

	- `1 <= a.length, b.length <= 10^4`

	- `a` and `b` consist of lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int cnt=0;
        string ans="";
        int na=a.size(), nb=b.size();
        int an=0;

        while(an<nb){
            ans+=a;
            an+=na;
            cnt++;
        }
        if(ans.find(b)!=string::npos){
            return cnt;
        }
        ans+=a;
        if(ans.find(b)!=string::npos){
            return cnt+1;
        }
        return -1;
    }
};
```
