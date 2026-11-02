# #204 — Count Primes

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 2 November 2026 at 01:01 pm IST |
| **Runtime** | 280 ms *(beats 58.3%)* |
| **Memory** | 13.8 MB *(beats 83.9%)* |
| **Topics** | `Array` `Math` `Enumeration` `Number Theory` `Primality Test` `Sieve Theory` `Prime Number Sieve` |

🔗 [View on LeetCode](https://leetcode.com/problems/count-primes/)

---

## 📋 Problem Description

Given an integer `n`, return *the number of prime numbers that are strictly less than* `n`.

 

**Example 1:**

```
**Input:** n = 10
**Output:** 4
**Explanation:** There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```
**Input:** n = 0
**Output:** 0
```

**Example 3:**

```
**Input:** n = 1
**Output:** 0
```

 

**Constraints:**

	- `0 <= n <= 5 * 10^6`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n<=2){
            return 0;
        }

        int ans=n;

        vector<bool> isp(n, true);
        isp[0]=isp[1]=false;
        ans-=2;

        for(long long i=2;i<n;i++){
            if(isp[i]){
                for(long long j=i*i;j<n;j+=i){
                    if(isp[j]){
                        ans--;
                    }
                    isp[j]=false;
                }
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

**Hint 1:** Checking all the integers in the range [1, n - 1] is not efficient. Think about a better approach.

**Hint 2:** Since most of the numbers are not primes, we need a fast approach to exclude the non-prime integers.

**Hint 3:** Use Sieve of Eratosthenes.

</details>
