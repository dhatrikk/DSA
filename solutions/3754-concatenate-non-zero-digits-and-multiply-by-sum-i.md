# #3754 — Concatenate Non-Zero Digits and Multiply by Sum I

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 7 July 2026 at 11:40 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.9 MB *(beats 89.1%)* |
| **Topics** | `Math` |

🔗 [View on LeetCode](https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/)

---

## 📋 Problem Description

You are given an integer `n`.

Form a new integer `x` by concatenating all the **non-zero digits** of `n` in their original order. If there are no **non-zero** digits, `x = 0`.

Let `sum` be the **sum of digits** in `x`.

Return an integer representing the value of `x * sum`.

 

**Example 1:**

**Input:** n = 10203004

**Output:** 12340

**Explanation:**

	- The non-zero digits are 1, 2, 3, and 4. Thus, `x = 1234`.

	- The sum of digits is `sum = 1 + 2 + 3 + 4 = 10`.

	- Therefore, the answer is `x * sum = 1234 * 10 = 12340`.

**Example 2:**

**Input:** n = 1000

**Output:** 1

**Explanation:**

	- The non-zero digit is 1, so `x = 1` and `sum = 1`.

	- Therefore, the answer is `x * sum = 1 * 1 = 1`.

 

**Constraints:**

	- `0 <= n <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum=0;
        long long ans=0;

        while(n){
            if(n%10==0){
                n=n/10;
            }else{
                sum+=n%10;
                ans=ans*10;
                ans+=n%10;
                n=n/10;
            }
        }
        n=ans;
        ans=0;
        while(n){
            if(n%10==0){
                n=n/10;
            }else{
                ans=ans*10;
                ans+=n%10;
                n=n/10;
            }
        }
        return sum*ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Simulate as described

</details>
