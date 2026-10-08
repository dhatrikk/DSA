# #136 — Single Number

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 07:44 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 20.7 MB *(beats 23.9%)* |
| **Topics** | `Array` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/single-number/)

---

## 📋 Problem Description

Given a **non-empty** array of integers `nums`, every element appears *twice* except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

**Example 1:**

**Input:** nums = [2,2,1]

**Output:** 1

**Example 2:**

**Input:** nums = [4,1,2,1,2]

**Output:** 4

**Example 3:**

**Input:** nums = [1]

**Output:** 1

 

**Constraints:**

	- `1 <= nums.length <= 3 * 10^4`

	- `-3 * 10^4 <= nums[i] <= 3 * 10^4`

	- Each element in the array appears twice except for one element which appears only once.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i:nums){
            xr^=i;
        }
        return xr;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think about the XOR (^) operator's property.

</details>
