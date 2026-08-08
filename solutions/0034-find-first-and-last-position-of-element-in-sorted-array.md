# #34 — Find First and Last Position of Element in Sorted Array

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 August 2026 at 02:33 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 17.7 MB *(beats 20.1%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

---

## 📋 Problem Description

Given an array of integers `nums` sorted in non-decreasing order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
**Input:** nums = [5,7,7,8,8,10], target = 8
**Output:** [3,4]
```
**Example 2:**

```
**Input:** nums = [5,7,7,8,8,10], target = 6
**Output:** [-1,-1]
```
**Example 3:**

```
**Input:** nums = [], target = 0
**Output:** [-1,-1]
```

 

**Constraints:**

	- `0 <= nums.length <= 10^5`

	- `-10^9 <= nums[i] <= 10^9`

	- `nums` is a non-decreasing array.

	- `-10^9 <= target <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        int l = 0, r = nums.size() - 1;
        int f = -1, e = -1, m;

        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] > t) {
                r = m - 1;
            } else if (nums[m] < t) {
                l = m + 1;
            } else {
                f = m;
                r = m - 1;
            }
        }
        if (f != -1) {
            l = f, r = nums.size() - 1;
            while (l <= r) {
                m = l + (r - l) / 2;
                if (nums[m] > t) {
                    r = m - 1;
                } else {
                    e = m;
                    l = m + 1;
                }
            }
        }
        return {f, e};
    }
};
```
