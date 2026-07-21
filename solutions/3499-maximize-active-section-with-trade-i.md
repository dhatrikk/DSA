# #3499 — Maximize Active Section with Trade I

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 July 2026 at 03:52 am IST |
| **Runtime** | 51 ms *(beats 76.3%)* |
| **Memory** | 54.8 MB *(beats 75.0%)* |
| **Topics** | `String` `Enumeration` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximize-active-section-with-trade-i/)

---

## 📋 Problem Description

You are given a binary string `s` of length `n`, where:

	- `'1'` represents an **active** section.

	- `'0'` represents an **inactive** section.

You can perform **at most one trade** to maximize the number of active sections in `s`. In a trade, you:

	- Convert a contiguous block of `'1'`s that is surrounded by `'0'`s to all `'0'`s.

	- Afterward, convert a contiguous block of `'0'`s that is surrounded by `'1'`s to all `'1'`s.

Return the **maximum** number of active sections in `s` after making the optimal trade.

**Note:** Treat `s` as if it is **augmented** with a `'1'` at both ends, forming `t = '1' + s + '1'`. The augmented `'1'`s **do not** contribute to the final count.

 

**Example 1:**

**Input:** s = "01"

**Output:** 1

**Explanation:**

Because there is no block of `'1'`s surrounded by `'0'`s, no valid trade is possible. The maximum number of active sections is 1.

**Example 2:**

**Input:** s = "0100"

**Output:** 4

**Explanation:**

	- String `"0100"` &rarr; Augmented to `"101001"`.

	- Choose `"0100"`, convert `"101001"` &rarr; `"100001"` &rarr; `"111111"`.

	- The final string without augmentation is `"1111"`. The maximum number of active sections is 4.

**Example 3:**

**Input:** s = "1000100"

**Output:** 7

**Explanation:**

	- String `"1000100"` &rarr; Augmented to `"110001001"`.

	- Choose `"000100"`, convert `"110001001"` &rarr; `"110000001"` &rarr; `"111111111"`.

	- The final string without augmentation is `"1111111"`. The maximum number of active sections is 7.

**Example 4:**

**Input:** s = "01010"

**Output:** 4

**Explanation:**

	- String `"01010"` &rarr; Augmented to `"1010101"`.

	- Choose `"010"`, convert `"1010101"` &rarr; `"1000101"` &rarr; `"1111101"`.

	- The final string without augmentation is `"11110"`. The maximum number of active sections is 4.

 

**Constraints:**

	- `1 <= n == s.length <= 10^5`

	- `s[i]` is either `'0'` or `'1'`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int left = 0, right = 0, one = 0, i, ans=0;

        for (char c : s) {
            i = c - '0';
            if (i == 1) {
                one++;
                if (right) {
                    left = right;
                    right = 0;
                }
            }else{
                right++;
            }
            if(left && right){
                ans=max(ans,left+right);
            }
        }

        return ans+one;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Split the string into several zero-one segments.

**Hint 2:** For each one-segment, if it has two neighbors (i.e., it is surrounded by two zero-segments), the total sum of their lengths is one of the candidates for `delta`.

**Hint 3:** Find the maximum `delta` and add it to the total number of ones in the string.

</details>
