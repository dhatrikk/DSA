# #3090 — Maximum Length Substring With Two Occurrences

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 14 August 2026 at 08:44 pm IST |
| **Runtime** | 2 ms *(beats 51.9%)* |
| **Memory** | 9.6 MB *(beats 57.7%)* |
| **Topics** | `Hash Table` `String` `Sliding Window` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)

---

## 📋 Problem Description

Given a string `s`, return the **maximum** length of a substring such that it contains *at most two occurrences* of each character.
 

**Example 1:**

**Input:** s = "bcbbbcba"

**Output:** 4

**Explanation:**

The following substring has a length of 4 and contains at most two occurrences of each character: `"bcbbbcba"`.

**Example 2:**

**Input:** s = "aaaa"

**Output:** 2

**Explanation:**

The following substring has a length of 2 and contains at most two occurrences of each character: `"aaaa"`.

 

**Constraints:**

	- `2 <= s.length <= 100`

	- `s` consists only of lowercase English letters.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int ans=0;

        int l=0;
        int n=s.size();

        for(int r=0;r<n;r++){
            mp[s[r]]++;
            while(mp[s[r]]>2 && l<=r){
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
        }
        
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** We can try all substrings by brute-force since the constraints are very small.

</details>
