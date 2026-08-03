# #560 — Subarray Sum Equals K

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 3 August 2026 at 05:46 am IST |
| **Runtime** | 55 ms *(beats 38.0%)* |
| **Memory** | 51 MB *(beats 20.0%)* |
| **Topics** | `Array` `Hash Table` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/subarray-sum-equals-k/)

---

## 📋 Problem Description

Given an array of integers `nums` and an integer `k`, return *the total number of subarrays whose sum equals to* `k`.

A subarray is a contiguous **non-empty** sequence of elements within an array.

 

**Example 1:**

```
**Input:** nums = [1,1,1], k = 2
**Output:** 2
```
**Example 2:**

```
**Input:** nums = [1,2,3], k = 3
**Output:** 2
```

 

**Constraints:**

	- `1 <= nums.length <= 2 * 10^4`

	- `-1000 <= nums[i] <= 1000`

	- `-10^7 <= k <= 10^7`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sum = 0;
        int ans = 0;
        mp[0]++;

        for (int i : nums) {
            sum += i;
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Will Brute force work here? Try to optimize it.

**Hint 2:** Can we optimize it by using some extra space?

**Hint 3:** What about storing sum frequencies in a hash table? Will it be useful?

**Hint 4:** sum(i,j)=sum(0,j)-sum(0,i), where sum(i,j) represents the sum of all the elements from index i to j-1.

Can we use this property to optimize it.

</details>
