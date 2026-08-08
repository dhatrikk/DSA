# #540 — Single Element in a Sorted Array

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 August 2026 at 06:45 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 26.1 MB *(beats 69.8%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/single-element-in-a-sorted-array/)

---

## 📋 Problem Description

You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return *the single element that appears only once*.

Your solution must run in `O(log n)` time and `O(1)` space.

 

**Example 1:**

```
**Input:** nums = [1,1,2,3,3,4,4,8,8]
**Output:** 2
```
**Example 2:**

```
**Input:** nums = [3,3,7,7,10,11,11]
**Output:** 10
```

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `0 <= nums[i] <= 10^5`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0, r=n-1, m;

        while(l<=r){
            m=l+(r-l)/2;
            if(m%2){
                if(m-1>=0 && nums[m]==nums[m-1]){
                    l=m+1;
                }else{
                    r=m-1;
                }
            }else{
                if(m+2<n && nums[m]==nums[m+1]){
                    l=m+2;
                }else if(m-2>=0 && nums[m]==nums[m-1]){
                    r=m-2;
                }else{
                    return nums[m];
                }
            }
        }
        return -1;
    }
};
```
