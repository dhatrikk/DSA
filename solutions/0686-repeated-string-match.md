# #686 — Repeated String Match

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 02:46 pm IST |
| **Runtime** | 2 ms *(beats 82.5%)* |
| **Memory** | 9.7 MB *(beats 81.6%)* |
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
    int mod = 1e9 + 7, base = 31;
    long long pw(int x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return x;
        }
        long long num = (pw(x, n / 2)) % mod;
        if (n % 2 == 1) {
            return ((num * num)%mod * x) % mod;
        }
        return (num * num) % mod;
    }
    bool f(string& s1, int n1, string& s2, int n2) {
        long long hash1 = 0, hash2 = 0;
        for (int i = 0; i < n1; i++) {
            hash1 = (hash1 * base) % mod;
            hash1 = (hash1 + (s1[i] - 'a' + 1)) % mod;
            hash2 = (hash2 * base) % mod;
            hash2 = (hash2 + (s2[i] - 'a' + 1)) % mod;
        }

        long long power= pw(base, n1 - 1);
        for (int i = n1; i < n2; i++) {
            if (hash1 == hash2 && s2.substr(i - n1, n1) == s1) {
                return true;
            }
            hash2 = (hash2 - ((s2[i - n1] - 'a' + 1) * power % mod) +
                     mod) %
                    mod;
            hash2 = (hash2 * base) % mod;
            hash2 = (hash2 + (s2[i] - 'a' + 1)) % mod;
        }
        if (hash1 == hash2 && s2.substr(n2 - n1, n1) == s1) {
                return true;
        }
        return false;
    }

public:
    int repeatedStringMatch(string a, string b) {
        int na = a.size(), nb = b.size();
        int ans = 1;
        int n = na;
        string s = a;
        while (n < nb) {
            s += a;
            ans++;
            n += na;
        }
        if (f(b, nb, s, n)) {
            return ans;
        }
        s += a;
        n += na;
        ans++;
        if (f(b, nb, s, n)) {
            return ans;
        }
        return -1;
    }
};
```
