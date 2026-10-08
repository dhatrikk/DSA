# #260 — Single Number III

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 08:28 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 14.1 MB *(beats 31.0%)* |
| **Topics** | `Array` `Bit Manipulation` |

🔗 [View on LeetCode](https://leetcode.com/problems/single-number-iii/)

---

## 📋 Problem Description

Given an integer array `nums`, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in **any order**.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

 

**Example 1:**

```
**Input:** nums = [1,2,1,3,2,5]
**Output:** [3,5]
**Explanation: ** [5, 3] is also a valid answer.
```

**Example 2:**

```
**Input:** nums = [-1,0]
**Output:** [-1,0]
```

**Example 3:**

```
**Input:** nums = [0,1]
**Output:** [1,0]
```

 

**Constraints:**

	- `2 <= nums.length <= 3 * 10^4`

	- `-2^31 <= nums[i] <= 2^31 - 1`

	- Each integer in `nums` will appear twice, only two integers will appear once.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xr=0;
        for(int i:nums){
            xr^=i;
        }

        int df=0;
        for(int i=0;1;i++){
            if(1<<i & xr){
                df=i;
                break;
            }
        }
        int y=0;
        for(int i:nums){
            if(1<<df & i){
                y^=i;
            }
        }

        xr^=y;

        return {xr, y};

    }
};
```
