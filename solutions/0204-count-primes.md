# #204 — Count Primes

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 07:21 pm IST |
| **Runtime** | 838 ms *(beats 8.0%)* |
| **Memory** | 320.7 MB *(beats 5.6%)* |
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
        int ans=n/2;
        vector<int> isp(n,1);

        for(int i=3;i*i<n;i+=2){
            if(isp[i]){
                for(int j=i*i;j<n;j+=2*i){
                    if(isp[j]){
                        isp[j]=0;
                        ans--;
                    }
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
