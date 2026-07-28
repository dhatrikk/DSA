# #3517 — Smallest Palindromic Rearrangement I

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 28 July 2026 at 07:54 pm IST |
| **Runtime** | 48 ms *(beats 50.1%)* |
| **Memory** | 54.1 MB *(beats 91.6%)* |
| **Topics** | `String` `Sorting` `Counting Sort` |

🔗 [View on LeetCode](https://leetcode.com/problems/smallest-palindromic-rearrangement-i/)

---

## 📋 Problem Description

You are given a **palindromic** string `s`.

Return the **lexicographically smallest** palindromic permutation of `s`.

 

**Example 1:**

**Input:** s = "z"

**Output:** "z"

**Explanation:**

A string of only one character is already the lexicographically smallest palindrome.

**Example 2:**

**Input:** s = "babab"

**Output:** "abbba"

**Explanation:**

Rearranging `"babab"` &rarr; `"abbba"` gives the smallest lexicographic palindrome.

**Example 3:**

**Input:** s = "daccad"

**Output:** "acddca"

**Explanation:**

Rearranging `"daccad"` &rarr; `"acddca"` gives the smallest lexicographic palindrome.

 

**Constraints:**

	- `1 <= s.length <= 10^5`

	- `s` consists of lowercase English letters.

	- `s` is guaranteed to be palindromic.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n<=3){
            return s;
        }
        sort(s.begin(), s.begin()+ (n/2));

        for(int i=0; i<n/2;i++){
            s[n-1-i]=s[i];
        }

        return s;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Consider a palindrome as composed of two mirror-image halves.

**Hint 2:** Construct one half (using `s`), and then the other half is its reverse to obtain the lexicographically smallest permutation.

</details>
