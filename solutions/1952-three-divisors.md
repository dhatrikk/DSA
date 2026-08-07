# #1952 — Three Divisors

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 8 August 2026 at 12:45 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 7.8 MB *(beats 58.9%)* |
| **Topics** | `Math` `Enumeration` `Number Theory` `Prime Factorization` `Sieve Theory` |

🔗 [View on LeetCode](https://leetcode.com/problems/three-divisors/)

---

## 📋 Problem Description

Given an integer `n`, return `true`* if *`n`* has **exactly three positive divisors**. Otherwise, return *`false`.

An integer `m` is a **divisor** of `n` if there exists an integer `k` such that `n = k * m`.

 

**Example 1:**

```
**Input:** n = 2
**Output:** false
**Explantion:** 2 has only two divisors: 1 and 2.
```

**Example 2:**

```
**Input:** n = 4
**Output:** true
**Explantion:** 4 has three divisors: 1, 2, and 4.
```

 

**Constraints:**

	- `1 <= n <= 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool isp(int n){
        if(n==1){
            return false;
        }
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
public:
    bool isThree(int n) {
        int r=sqrt(n);
        return (r*r == n) && isp(r);
    }
};


// class Solution {
// public:
//     bool isThree(int n) {
//         int cnt=0;
//         for(int i=1;i*i<=n;i++){
//             if(i*i==n){
//                 cnt++;
//             }else if(n%i==0){
//                 cnt+=2;
//             }
//         }
//         if(cnt==3){
//             return true;
//         }
//         return false;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** You can count the number of divisors and just check that they are 3

**Hint 2:** Beware of the case of n equal 1 as some solutions might fail in it

</details>
