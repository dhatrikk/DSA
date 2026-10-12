# #424 — Longest Repeating Character Replacement

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 12 October 2026 at 09:03 pm IST |
| **Runtime** | 1 ms *(beats 73.9%)* |
| **Memory** | 10.8 MB *(beats 70.7%)* |
| **Topics** | `Hash Table` `String` `Sliding Window` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-repeating-character-replacement/)

---

## 📋 Problem Description

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return *the length of the longest substring containing the same letter you can get after performing the above operations*.

 

**Example 1:**

```
**Input:** s = "ABAB", k = 2
**Output:** 4
**Explanation:** Replace the two 'A's with two 'B's or vice versa.
```

**Example 2:**

```
**Input:** s = "AABABBA", k = 1
**Output:** 4
**Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
```

 

**Constraints:**

	- `1 <= s.length <= 10^5`

	- `s` consists of only uppercase English letters.

	- `0 <= k <= s.length`

---

## ✅ Accepted Solution

```cpp
class Solution {
    int fmx(vector<int>& arr){
        int mx=0;
        for(int i=0;i<26;i++){
            mx=max(mx, arr[i]);
        }
        return mx;
    }

public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int l=0, r=0;
        int ans=0, mx=0;
        vector<int> arr(26, 0);

        while(r<n){
            arr[s[r]-'A']++;
            mx=max(mx, arr[s[r]-'A']);
            while(r-l+1>mx+k && l<r){
                arr[s[l]-'A']--;
                mx=fmx(arr);
                l++;
            }
            if(r-l+1<=mx+k){
                ans=max(ans, r-l+1);
            }
            r++;
        }
        return ans;
    }
};
```
