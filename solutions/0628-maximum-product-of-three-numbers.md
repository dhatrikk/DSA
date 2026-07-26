# #628 — Maximum Product of Three Numbers

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 26 July 2026 at 05:52 pm IST |
| **Runtime** | 11 ms *(beats 37.4%)* |
| **Memory** | 31.6 MB *(beats 10.4%)* |
| **Topics** | `Array` `Math` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-product-of-three-numbers/)

---

## 📋 Problem Description

Given an integer array `nums`, *find three numbers whose product is maximum and return the maximum product*.

 

**Example 1:**

```
**Input:** nums = [1,2,3]
**Output:** 6
```
**Example 2:**

```
**Input:** nums = [1,2,3,4]
**Output:** 24
```
**Example 3:**

```
**Input:** nums = [-1,-2,-3]
**Output:** -6
```

 

**Constraints:**

	- `3 <= nums.length <= 10^4`

	- `-1000 <= nums[i] <= 1000`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n =nums.size();
        return max((nums[0]*nums[1]*nums[2]),(nums[n-1]*nums[n-2]*nums[0]));
    }
};
```
