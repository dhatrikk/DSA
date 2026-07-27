# #169 — Majority Element

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 28 July 2026 at 03:55 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 28.1 MB *(beats 92.1%)* |
| **Topics** | `Array` `Hash Table` `Divide and Conquer` `Sorting` `Counting` |

🔗 [View on LeetCode](https://leetcode.com/problems/majority-element/)

---

## 📋 Problem Description

Given an array `nums` of size `n`, return *the majority element*.

The majority element is the element that appears more than `&lfloor;n / 2&rfloor;` times. You may assume that the majority element always exists in the array.

 

**Example 1:**

```
**Input:** nums = [3,2,3]
**Output:** 3
```
**Example 2:**

```
**Input:** nums = [2,2,1,1,1,2,2]
**Output:** 2
```

 

**Constraints:**

	- `n == nums.length`

	- `1 <= n <= 5 * 10^4`

	- `-10^9 <= nums[i] <= 10^9`

	- The input is generated such that a majority element will exist in the array.

 

**Follow-up:** Could you solve the problem in linear time and in `O(1)` space?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int num;

        for(int i:nums){
            if(cnt==0){
                num=i;
            }
            if(num==i){
                cnt++;
            }else{
                cnt--;
            }
        }
        return num;
    }
};



// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());

//         int cnt=1, num=nums[0], n=nums.size();
//         for(int i=1;i<n;i++){
//             if(nums[i]==num){
//                 cnt++;
//             }else{
//                 num=nums[i];
//                 cnt=1; 
//             }
//             if(cnt*2>n){
//                 break;
//             }
//         }
//         return num;
//     }
// };
```
