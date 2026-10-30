# #217 — Contains Duplicate

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 05:09 am IST |
| **Runtime** | 26 ms *(beats 20.0%)* |
| **Memory** | 32.9 MB *(beats 21.5%)* |
| **Topics** | `Array` `Hash Table` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/contains-duplicate/)

---

## 📋 Problem Description

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

 

**Example 1:**

**Input:** nums = [1,2,3,1]

**Output:** true

**Explanation:**

The element 1 occurs at the indices 0 and 3.

**Example 2:**

**Input:** nums = [1,2,3,4]

**Output:** false

**Explanation:**

All elements are distinct.

**Example 3:**

**Input:** nums = [1,1,1,3,3,4,3,2,4,2]

**Output:** true

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `-10^9 <= nums[i] <= 10^9`

---

## ✅ Accepted Solution

```python
class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        st = set()

        for i in range(0, len(nums), 1):
            if nums[i] in st:
                return True 
            else:
                st.add(nums[i])   
        
        return False
```
