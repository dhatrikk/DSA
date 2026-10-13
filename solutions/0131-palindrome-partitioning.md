# #131 — Palindrome Partitioning

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 14 October 2026 at 02:41 am IST |
| **Runtime** | 41 ms *(beats 62.2%)* |
| **Memory** | 53.2 MB *(beats 99.7%)* |
| **Topics** | `String` `Dynamic Programming` `Backtracking` |

🔗 [View on LeetCode](https://leetcode.com/problems/palindrome-partitioning/)

---

## 📋 Problem Description

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**. Return *all possible palindrome partitioning of *`s`.

 

**Example 1:**

```
**Input:** s = "aab"
**Output:** [["a","a","b"],["aa","b"]]
```
**Example 2:**

```
**Input:** s = "a"
**Output:** [["a"]]
```

 

**Constraints:**

	- `1 <= s.length <= 16`

	- `s` contains only lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool isp(string& s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

    void f(string& s, int l, int n, vector<vector<string>>& ans, vector<string>& curr) {
        if (l == n) {
            ans.push_back(curr);
            return;
        }
        for (int i = 0; i < n - l; i++) {
            if (isp(s, l, l+i)) {
                curr.push_back(s.substr(l, i+1));
                f(s, l + i + 1, n, ans, curr);
                curr.pop_back();
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        f(s, 0, s.size(), ans, curr);
        return ans;
    }
};
```
