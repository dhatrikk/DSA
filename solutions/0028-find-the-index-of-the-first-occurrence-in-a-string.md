# #28 — Find the Index of the First Occurrence in a String

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 18 August 2026 at 02:54 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 9.5 MB *(beats 10.6%)* |
| **Topics** | `Two Pointers` `String` `String Matching` `Z Algorithm` `Knuth–Morris–Pratt Algorithm` `Boyer–Moore String-Search Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

---

## 📋 Problem Description

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

 

**Example 1:**

```
**Input:** haystack = "sadbutsad", needle = "sad"
**Output:** 0
**Explanation:** "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
```

**Example 2:**

```
**Input:** haystack = "leetcode", needle = "leeto"
**Output:** -1
**Explanation:** "leeto" did not occur in "leetcode", so we return -1.
```

 

**Constraints:**

	- `1 <= haystack.length, needle.length <= 10^4`

	- `haystack` and `needle` consist of only lowercase English characters.

---

## ✅ Accepted Solution

```cpp
class Solution {
    vector<int> lps(string& s) {
        int n = s.size();
        vector<int> v(n);
        int len = 0;
        int i = 1;

        while (i < n) {
            if (s[i] == s[len]) {
                len++;
                v[i] = len;
                i++;
            } else if (len) {
                len = v[len - 1];
            } else {
                i++;
            }
        }
        return v;
    }

public:
    int strStr(string h, string ne) {
        vector<int> v = lps(ne);
        int i = 0, j = 0, n = ne.size(), m = h.size();

        while (j < m) {
            if (h[j] == ne[i]) {
                i++;
                j++;
            } else if(i>0){
                i = v[i - 1];
            }else{
                j++;
            }
            if (i == n) {
                return j - n;
            }
        }
        return -1;
    }
};
```
