# #3536 — Maximum Product of Two Digits

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 25 July 2026 at 03:30 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.5 MB *(beats 89.7%)* |
| **Topics** | `Math` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-product-of-two-digits/)

---

## 📋 Problem Description

You are given a positive integer `n`.

Return the **maximum** product of any two digits in `n`.

**Note:** You may use the **same** digit twice if it appears more than once in `n`.

 

**Example 1:**

**Input:** n = 31

**Output:** 3

**Explanation:**

	- The digits of `n` are `[3, 1]`.

	- The possible products of any two digits are: `3 * 1 = 3`.

	- The maximum product is 3.

**Example 2:**

**Input:** n = 22

**Output:** 4

**Explanation:**

	- The digits of `n` are `[2, 2]`.

	- The possible products of any two digits are: `2 * 2 = 4`.

	- The maximum product is 4.

**Example 3:**

**Input:** n = 124

**Output:** 8

**Explanation:**

	- The digits of `n` are `[1, 2, 4]`.

	- The possible products of any two digits are: `1 * 2 = 2`, `1 * 4 = 4`, `2 * 4 = 8`.

	- The maximum product is 8.

 

**Constraints:**

	- `10 <= n <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxProduct(int n) {
        int m=0,sm=0,k;

        while(n){
            k=n%10;
            if(k>=m){
                sm=m;
                m=k;
            }
            if(k>sm && k<m){
                sm=k;
            }
            n=n/10;
        }

        return m*sm;

    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Use brute force

</details>
