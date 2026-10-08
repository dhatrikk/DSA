# #3 — Longest Substring Without Repeating Characters

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 October 2026 at 01:49 am IST |
| **Runtime** | 3 ms *(beats 97.1%)* |
| **Memory** | 18.5 MB *(beats 90.1%)* |
| **Topics** | `Hash Table` `String` `Sliding Window` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

---

## 📋 Problem Description

Given a string `s`, find the length of the **longest** **substring** without duplicate characters.

 

**Example 1:**

```
**Input:** s = "abcabcbb"
**Output:** 3
**Explanation:** The answer is "abc", with the length of 3. Note that `"bca"` and `"cab"` are also correct answers.
```

**Example 2:**

```
**Input:** s = "bbbbb"
**Output:** 1
**Explanation:** The answer is "b", with the length of 1.
```

**Example 3:**

```
**Input:** s = "pwwkew"
**Output:** 3
**Explanation:** The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

 

**Constraints:**

	- `0 <= s.length <= 10^5`

	- `s` consists of English letters, digits, symbols and spaces.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, r=0, ans=0;
        vector<int> preind(128, -1);

        while(r<s.size()){
            if(preind[s[r]]>=l){
                l=preind[s[r]]+1;
            }
            preind[s[r]]=r;
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};



// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> arr(128, 0);
//         int l = 0, r = 0, ans=0;
//         while (r < s.size()) {
//             arr[s[r]]++;
//             while (arr[s[r]] > 1 && l <= r) {
//                 arr[s[l]]--;
//                 l++;
//             }
//             ans=max(ans, r-l+1);
//             r++;
//         }
//         return ans;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** There are less than 100 unique characters. We can check all substrings with length at most 100 for example. This is a good enough approximation.

</details>
