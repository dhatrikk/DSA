# #3518 — Smallest Palindromic Rearrangement II

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 30 July 2026 at 10:03 pm IST |
| **Runtime** | 32 ms *(beats 44.3%)* |
| **Memory** | 16 MB *(beats 81.7%)* |
| **Topics** | `Hash Table` `Math` `String` `Combinatorics` `Counting` |

🔗 [View on LeetCode](https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/)

---

## 📋 Problem Description

You are given a **palindromic** string `s` and an integer `k`.

Return the **k-th** **lexicographically smallest** palindromic permutation of `s`. If there are fewer than `k` distinct palindromic permutations, return an empty string.

**Note:** Different rearrangements that yield the same palindromic string are considered identical and are counted once.

 

**Example 1:**

**Input:** s = "abba", k = 2

**Output:** "baab"

**Explanation:**

	- The two distinct palindromic rearrangements of `"abba"` are `"abba"` and `"baab"`.

	- Lexicographically, `"abba"` comes before `"baab"`. Since `k = 2`, the output is `"baab"`.

**Example 2:**

**Input:** s = "aa", k = 2

**Output:** ""

**Explanation:**

	- There is only one palindromic rearrangement: `"aa"`.

	- The output is an empty string since `k = 2` exceeds the number of possible rearrangements.

**Example 3:**

**Input:** s = "bacab", k = 1

**Output:** "abcba"

**Explanation:**

	- The two distinct palindromic rearrangements of `"bacab"` are `"abcba"` and `"bacab"`.

	- Lexicographically, `"abcba"` comes before `"bacab"`. Since `k = 1`, the output is `"abcba"`.

 

**Constraints:**

	- `1 <= s.length <= 10^4`

	- `s` consists of lowercase English letters.

	- `s` is guaranteed to be palindromic.

	- `1 <= k <= 10^6`

---

## ✅ Accepted Solution

```cpp
class Solution {

    long long ncr(int n, int r, int k) {

        long long ans = 1;
        r = min(r, n - r);

        for (int i = 1; i <= r; i++) {
            ans *= (n - r + i);
            ans /= (i);
            if (ans > k) {
                return k;
            }
        }
        return ans;
    }

public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        string ans = "";

        vector<int> alpha(26, 0);
        for (int i = 0; i < n / 2; i++) {
            alpha[s[i] - 'a']++;
        }

        long long ways = 1;
        int place = n / 2;
        for (int it : alpha) {
            if (it > 0) {
                ways *= ncr(place, it, k);
                ways=min(ways, (long long)k);
                place -= it;
            }
        }
        if (ways < k) {
            return ans;
        }

        for (int i = 0; i < n / 2; i++) {
            for (int ch = 0; ch < 26; ch++) {
                if (alpha[ch] > 0) {
                    alpha[ch]--;
                    ways = 1;
                    place = (n / 2) - i-1;
                    for (int j = 0; j < 26; j++) {
                        if (alpha[j]) {
                            ways *= ncr(place, alpha[j], k);
                            ways=min(ways, (long long)k);
                            place -= alpha[j];
                        }
                    }
                    if (k <= ways) {
                        ans += ('a' + ch);
                        break;
                    }
                    k -= ways;
                    alpha[ch]++;
                }
            }
        }

        if (n % 2) {
            ans += s[n / 2];
        }
        for (int i = n/2 -1; i>=0; i--) {
            ans+= ans[i];
        }

        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Only build `floor(n / 2)` characters (the rest are determined by symmetry).

**Hint 2:** Count character frequencies and use half the counts for construction.

**Hint 3:** Incrementally choose each character (from smallest to largest) and calculate how many valid arrangements result if that character is chosen at the current index.

**Hint 4:** If the count is at least `k`, fix that character; otherwise, subtract the count from `k` and try the next candidate.

**Hint 5:** Use combinatorics to compute the number of permutations at each step.

</details>
