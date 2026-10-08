# #137 — Single Number II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 09:46 pm IST |
| **Runtime** | 1 ms *(beats 44.2%)* |
| **Memory** | 13.4 MB *(beats 35.9%)* |
| **Topics** | `Array` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/single-number-ii/)

---

## 📋 Problem Description

Given an integer array `nums` where every element appears **three times** except for one, which appears **exactly once**. *Find the single element and return it*.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

**Example 1:**

```
**Input:** nums = [2,2,3,2]
**Output:** 3
```
**Example 2:**

```
**Input:** nums = [0,1,0,1,0,1,99]
**Output:** 99
```

 

**Constraints:**

	- `1 <= nums.length <= 3 * 10^4`

	- `-2^31 <= nums[i] <= 2^31 - 1`

	- Each element in `nums` appears exactly **three times** except for one element which appears **once**.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> arr(32,0);
        for(int bit=0;bit<32;bit++){
            for(int j:nums){
                if(1<<bit & j){
                    arr[bit]++;
                    arr[bit]=arr[bit]%3;
                }
            }
        }
        long long ans=0;
        for(int i=0;i<32;i++){
            ans+=arr[i]*pow(2,i);
        }
        return ans;
    }
};
```
