# #14 — Longest Common Prefix

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 5 August 2026 at 02:58 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 11.8 MB *(beats 57.4%)* |
| **Topics** | `Array` `String` `Trie` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-common-prefix/)

---

## 📋 Problem Description

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

 

**Example 1:**

```
**Input:** strs = ["flower","flow","flight"]
**Output:** "fl"
```

**Example 2:**

```
**Input:** strs = ["dog","racecar","car"]
**Output:** ""
**Explanation:** There is no common prefix among the input strings.
```

 

**Constraints:**

	- `1 <= strs.length <= 200`

	- `0 <= strs[i].length <= 200`

	- `strs[i]` consists of only lowercase English letters if it is non-empty.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        int ms=INT_MAX;
        for(int i=0;i<n;i++){
            ms=min(ms,(int)strs[i].size());
        }
        string ans="";
        char c;
        for(int ind=0;ind<ms;ind++){
            c=strs[0][ind];
            for(int i=1;i<n;i++){
                if(c!=strs[i][ind]){
                    return ans;
                }
            }
            ans+=c;
        }
        return ans;
    }
};
```
