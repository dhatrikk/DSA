# #516 — Longest Palindromic Subsequence

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 30 September 2026 at 11:33 am IST |
| **Runtime** | 89 ms *(beats 34.9%)* |
| **Memory** | 76.1 MB *(beats 22.8%)* |
| **Topics** | `String` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-palindromic-subsequence/)

---

## 📋 Problem Description

Given a string `s`, find *the longest palindromic **subsequence**'s length in* `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

**Example 1:**

```
**Input:** s = "bbbab"
**Output:** 4
**Explanation:** One possible longest palindromic subsequence is "bbbb".
```

**Example 2:**

```
**Input:** s = "cbbd"
**Output:** 2
**Explanation:** One possible longest palindromic subsequence is "bb".
```

 

**Constraints:**

	- `1 <= s.length <= 1000`

	- `s` consists only of lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int longestPalindromeSubseq(string s2) {
        string s1=s2;
        reverse(s2.begin(), s2.end());
        int n=s1.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1,0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
                }
            }
        }

        return dp[n][n];
    }
};
```
