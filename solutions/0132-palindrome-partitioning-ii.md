# #132 — Palindrome Partitioning II

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 14 October 2026 at 03:37 am IST |
| **Runtime** | 1611 ms *(beats 22.4%)* |
| **Memory** | 9.3 MB *(beats 78.7%)* |
| **Topics** | `String` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/palindrome-partitioning-ii/)

---

## 📋 Problem Description

Given a string `s`, partition `s` such that every substring of the partition is a palindrome.

Return *the **minimum** cuts needed for a palindrome partitioning of* `s`.

 

**Example 1:**

```
**Input:** s = "aab"
**Output:** 1
**Explanation:** The palindrome partitioning ["aa","b"] could be produced using 1 cut.
```

**Example 2:**

```
**Input:** s = "a"
**Output:** 0
```

**Example 3:**

```
**Input:** s = "ab"
**Output:** 1
```

 

**Constraints:**

	- `1 <= s.length <= 2000`

	- `s` consists of lowercase English letters only.

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool isp(string& s, int i, int j){
        while(i<=j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }

    int f(string& s, int l, int n, vector<int>& dp){
        if(l>=n){
            return 0;
        }
        if(dp[l]!=-1){
            return dp[l];
        }
        if(isp(s, l, n-1)){
            return dp[l]=0;
        }
        int ans=1e9;
        for(int p=l;p<n;p++){
            if(isp(s, l, p)){
                ans=min(ans, 1 + f(s, p+1, n, dp));
            }
        }
        return dp[l]=ans;
    }

public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n, -1);
        return f(s, 0, n, dp);
    }
};
```
