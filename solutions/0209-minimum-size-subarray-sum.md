# #209 — Minimum Size Subarray Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 27 July 2026 at 04:30 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 41.8 MB *(beats 65.4%)* |
| **Topics** | `Array` `Binary Search` `Sliding Window` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-size-subarray-sum/)

---

## 📋 Problem Description

Given an array of positive integers `nums` and a positive integer `target`, return *the **minimal length** of a **subarray** whose sum is greater than or equal to* `target`. If there is no such subarray, return `0` instead.

 

**Example 1:**

```
**Input:** target = 7, nums = [2,3,1,2,4,3]
**Output:** 2
**Explanation:** The subarray [4,3] has the minimal length under the problem constraint.
```

**Example 2:**

```
**Input:** target = 4, nums = [1,4,4]
**Output:** 1
```

**Example 3:**

```
**Input:** target = 11, nums = [1,1,1,1,1,1,1,1]
**Output:** 0
```

 

**Constraints:**

	- `1 <= target <= 10^9`

	- `1 <= nums.length <= 10^5`

	- `1 <= nums[i] <= 10^4`

 

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution of which the time complexity is `O(n log(n))`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(right<nums.size()){
            sum+=nums[right];
            right++;
            while(sum>=target && left<right){
                ans=min(ans,right-left);
                sum-=nums[left];
                left++;
            }
        }
        
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};
```
