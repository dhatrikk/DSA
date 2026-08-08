# #154 — Find Minimum in Rotated Sorted Array II

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 8 August 2026 at 05:57 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 16.3 MB *(beats 29.4%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/)

---

## 📋 Problem Description

Suppose an array of length `n` sorted in ascending order is **rotated** between `1` and `n` times. For example, the array `nums = [0,1,4,4,5,6,7]` might become:

	- `[4,5,6,7,0,1,4]` if it was rotated `4` times.

	- `[0,1,4,4,5,6,7]` if it was rotated `7` times.

Notice that **rotating** an array `[a[0], a[1], a[2], ..., a[n-1]]` 1 time results in the array `[a[n-1], a[0], a[1], a[2], ..., a[n-2]]`.

Given the sorted rotated array `nums` that may contain **duplicates**, return *the minimum element of this array*.

You must decrease the overall operation steps as much as possible.

 

**Example 1:**

```
**Input:** nums = [1,3,5]
**Output:** 1
```
**Example 2:**

```
**Input:** nums = [2,2,2,0,1]
**Output:** 0
```

 

**Constraints:**

	- `n == nums.length`

	- `1 Find Minimum in Rotated Sorted Array, but `nums` may contain **duplicates**. Would this affect the runtime complexity? How and why?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        while(r>=0 && nums[0]==nums[r]){
            r--;
        }
        int ans=nums[0];

        while(l<=r){
            int m=l+(r-l)/2;
            if(nums[m]<nums[0]){
                r=m-1;
                ans=nums[m];
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
```
