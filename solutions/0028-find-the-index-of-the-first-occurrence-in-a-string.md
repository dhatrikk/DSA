# #28 — Find the Index of the First Occurrence in a String

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 15 October 2026 at 04:29 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 9.3 MB *(beats 24.7%)* |
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
    void f(vector<int>& lps, string& s, int n) {
        int len = 0;
        lps[0] = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[len]) {
                len++;
            } else {
                while (len > 0 && s[i] != s[len]) {
                    len = lps[len - 1];
                }
                if (s[i] == s[len]) {
                    len++;
                }
            }
            lps[i] = len;
        }
        return;
    }

public:
    int strStr(string hs, string nd) {
        int h = hs.size(), n = nd.size();
        if(n==0){
            return 0;
        }
        if(n>h){
            return -1;
        }
        vector<int> lps(n);
        f(lps, nd, n);

        int i = 0, j = 0;
        while (i < h) {
            if (hs[i] == nd[j]) {
                i++;
                j++;
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
            if (j == n) {
                return i - n;
            }
        }

        return -1;
    }
};
```
