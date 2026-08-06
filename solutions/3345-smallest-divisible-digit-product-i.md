# #3345 — Smallest Divisible Digit Product I

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 6 August 2026 at 06:13 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 8.7 MB *(beats 37.8%)* |
| **Topics** | `Math` `Enumeration` |

🔗 [View on LeetCode](https://leetcode.com/problems/smallest-divisible-digit-product-i/)

---

## 📋 Problem Description

You are given two integers `n` and `t`. Return the **smallest** number greater than or equal to `n` such that the **product of its digits** is divisible by `t`.

 

**Example 1:**

**Input:** n = 10, t = 2

**Output:** 10

**Explanation:**

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

**Example 2:**

**Input:** n = 15, t = 3

**Output:** 16

**Explanation:**

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

 

**Constraints:**

	- `1 <= n <= 100`

	- `1 <= t <= 10`

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool f(int n, int& t){

        int k=1;

        while(n){
            k*=(n%10);
            if(k%t==0){
                return true;
            }
            n/=10;
        }

        return false;
    }
public:
    int smallestNumber(int n, int t) {
        
        while(n){
            if(f(n,t)){
                return n;
            }
            n++;
        }
        return 0;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** You have to check at most 10 numbers.

**Hint 2:** Apply a brute-force approach by checking each possible number.

</details>
