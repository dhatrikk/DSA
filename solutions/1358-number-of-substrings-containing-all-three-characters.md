# #1358 — Number of Substrings Containing All Three Characters

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 12 October 2026 at 07:39 am IST |
| **Runtime** | 1 ms *(beats 93.2%)* |
| **Memory** | 10.9 MB *(beats 94.8%)* |
| **Topics** | `Hash Table` `String` `Sliding Window` |

🔗 [View on LeetCode](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

---

## 📋 Problem Description

Given a string `s` consisting only of characters *a*, *b* and *c*.

Return the number of substrings containing **at least** one occurrence of all these characters *a*, *b* and *c*.

 

**Example 1:**

```
**Input:** s = "abcabc"
**Output:** 10
**Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c are "*abc*", "*abca*", "*abcab*", "*abcabc*", "*bca*", "*bcab*", "*bcabc*", "*cab*", "*cabc*" *and* "*abc*" *(**again**)*. *
```

**Example 2:**

```
**Input:** s = "aaacb"
**Output:** 3
**Explanation:** The substrings containing at least one occurrence of the characters *a*, *b* and *c are "*aaacb*", "*aacb*" *and* "*acb*".** *
```

**Example 3:**

```
**Input:** s = "abc"
**Output:** 1
```

 

**Constraints:**

	- `3 <= s.length <= 5 x 10^4`

	- `s` only consists of `'a'`, `'b'` or `'c'` characters.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int a = 0, b = 0, c = 0;
        if (s[r] == 'a') {
            a++;
        } else if (s[r] == 'b') {
            b++;
        } else if (s[r] == 'c') {
            c++;
        }
        int ans = 0;

        while (l <= r) {
            while ((a == 0 || b == 0 || c == 0) && r < n) {
                r++;
                if (s[r] == 'a') {
                    a++;
                } else if (s[r] == 'b') {
                    b++;
                } else if (s[r] == 'c') {
                    c++;
                }
            }
            if (a && b && c) {
                ans += (n - r);
            }
            if (s[l] == 'a') {
                a--;
            } else if (s[l] == 'b') {
                b--;
            } else if (s[l] == 'c') {
                c--;
            }
            l++;
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** For each position we simply need to find the first occurrence of a/b/c on or after this position.

**Hint 2:** So we can pre-compute three link-list of indices of each a, b, and c.

</details>
