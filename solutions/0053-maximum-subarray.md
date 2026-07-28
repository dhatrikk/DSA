# #53 — Maximum Subarray

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 29 July 2026 at 03:47 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 71.7 MB *(beats 53.2%)* |
| **Topics** | `Array` `Divide and Conquer` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-subarray/)

---

## 📋 Problem Description

Given an integer array `nums`, find the subarray with the largest sum, and return *its sum*.

 

**Example 1:**

```
**Input:** nums = [-2,1,-3,4,-1,2,1,-5,4]
**Output:** 6
**Explanation:** The subarray [4,-1,2,1] has the largest sum 6.
```

**Example 2:**

```
**Input:** nums = [1]
**Output:** 1
**Explanation:** The subarray [1] has the largest sum 1.
```

**Example 3:**

```
**Input:** nums = [5,4,-1,7,8]
**Output:** 23
**Explanation:** The subarray [5,4,-1,7,8] has the largest sum 23.
```

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `-10^4 <= nums[i] <= 10^4`

 

**Follow up:** If you have figured out the `O(n)` solution, try coding another solution using the **divide and conquer** approach, which is more subtle.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0, ans=INT_MIN;
        for(int n:nums){
            sum+=n;
            ans=max(sum,ans);
            if(sum<0){
                sum=0;
            }
        }
        return ans;
    }
};
```
