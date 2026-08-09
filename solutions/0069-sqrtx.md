# #69 — Sqrt(x)

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 08:49 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.4 MB *(beats 87.9%)* |
| **Topics** | `Math` `Binary Search` `Newton's Method` |

🔗 [View on LeetCode](https://leetcode.com/problems/sqrtx/)

---

## 📋 Problem Description

Given a non-negative integer `x`, return *the square root of *`x`* rounded down to the nearest integer*. The returned integer should be **non-negative** as well.

You **must not use** any built-in exponent function or operator.

	- For example, do not use `pow(x, 0.5)` in c++ or `x ** 0.5` in python.

 

**Example 1:**

```
**Input:** x = 4
**Output:** 2
**Explanation:** The square root of 4 is 2, so we return 2.
```

**Example 2:**

```
**Input:** x = 8
**Output:** 2
**Explanation:** The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
```

 

**Constraints:**

	- `0 <= x <= 2^31 - 1`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int mySqrt(int x) {
        if(x==1){
            return 1;
        }
        int l=0, r=x/2;
        int m, ans=0;
        while(l<=r){
            m=l+(r-l)/2;
            if((1ll)*m*m<=x){
                ans=m;
                l=m+1;
            }else{
                r=m-1;
            }
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Try exploring all integers. (Credits: @annujoshi)

**Hint 2:** Use the sorted property of integers to reduced the search space. (Credits: @annujoshi)

</details>
