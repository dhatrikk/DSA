# #704 — Binary Search

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 05:44 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 20.6 MB *(beats 33.8%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-search/)

---

## 📋 Problem Description

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
**Input:** nums = [-1,0,3,5,9,12], target = 9
**Output:** 4
**Explanation:** 9 exists in nums and its index is 4
```

**Example 2:**

```
**Input:** nums = [-1,0,3,5,9,12], target = 2
**Output:** -1
**Explanation:** 2 does not exist in nums so return -1
```

 

**Constraints:**

	- `1 <= nums.length <= 10^4`

	- `-10^4 < nums[i], target < 10^4`

	- All the integers in `nums` are **unique**.

	- `nums` is sorted in ascending order.

---

## ✅ Accepted Solution

```python
class Solution:
    def search(self, nums: list[int], target: int) -> int:
        
        l=0 
        r=len(nums)-1

        while l<=r:
            mid=l+(r-l)//2

            if nums[mid]>target:
                r=mid-1
            elif nums[mid]<target:
                l=mid+1
            else:
                return mid       

        return -1
```
