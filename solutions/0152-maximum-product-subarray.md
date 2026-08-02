# #152 — Maximum Product Subarray

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 3 August 2026 at 05:10 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 17.6 MB *(beats 87.5%)* |
| **Topics** | `Array` `Dynamic Programming` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximum-product-subarray/)

---

## 📋 Problem Description

Given an integer array `nums`, find a subarray that has the largest product, and return *the product*.

The test cases are generated so that the answer will fit in a **32-bit** integer.

**Note** that the product of an array with a single element is the value of that element.

 

**Example 1:**

```
**Input:** nums = [2,3,-2,4]
**Output:** 6
**Explanation:** [2,3] has the largest product 6.
```

**Example 2:**

```
**Input:** nums = [-2,0,-1]
**Output:** 0
**Explanation:** The result cannot be 2, because [-2,-1] is not a subarray.
```

 

**Constraints:**

	- `1 <= nums.length <= 2 * 10^4`

	- `-10 <= nums[i] <= 10`

	- The product of any subarray of `nums` is **guaranteed** to fit in a **32-bit** integer.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre=1;
        int suf=1;
        int n=nums.size();
        int ans=INT_MIN;

        for(int i=0;i<n;i++){
            pre*=nums[i];
            suf*=nums[n-1-i];
            ans=max(ans,max(suf,pre));
            if(pre==0){
                pre=1;
            }
            if(suf==0){
                suf=1;
            }
            
        }
        return ans;
    }
};
```
