# #137 — Single Number II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 October 2026 at 01:24 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 13.3 MB *(beats 87.3%)* |
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
        int one = 0, two = 0;

        for (int i : nums) {
            one = (one ^ i) & ~two;
            two = (two ^ i) & ~one;
        }

        return one;
    }
};

// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {
//         vector<int> arr(32,0);
//         for(int bit=0;bit<32;bit++){
//             for(int j:nums){
//                 if(1<<bit & j){
//                     arr[bit]++;
//                     arr[bit]=arr[bit]%3;
//                 }
//             }
//         }
//         int ans=0;
//         for(int i=0;i<32;i++){
//             ans |= (arr[i]<<i);
//         }
//         return ans;
//     }
// };
```
