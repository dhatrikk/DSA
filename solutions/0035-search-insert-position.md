# #35 — Search Insert Position

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 8 August 2026 at 01:07 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 13.5 MB *(beats 98.8%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/search-insert-position/)

---

## 📋 Problem Description

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with `O(log n)` runtime complexity.

 

**Example 1:**

```
**Input:** nums = [1,3,5,6], target = 5
**Output:** 2
```

**Example 2:**

```
**Input:** nums = [1,3,5,6], target = 2
**Output:** 1
```

**Example 3:**

```
**Input:** nums = [1,3,5,6], target = 7
**Output:** 4
```

 

**Constraints:**

	- `1 <= nums.length <= 10^4`

	- `-10^4 <= nums[i] <= 10^4`

	- `nums` contains **distinct** values sorted in **ascending** order.

	- `-10^4 <= target <= 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ans=nums.size();
        int l=0, r=nums.size()-1, m;

        while(l<=r){
            m=l+(r-l)/2;
            if(nums[m]>=target){
                ans=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};
```
