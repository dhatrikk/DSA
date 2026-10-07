# #1827 — Minimum Operations to Make the Array Increasing

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 03:50 am IST |
| **Runtime** | 16 ms *(beats 17.9%)* |
| **Memory** | 19.7 MB *(beats 28.1%)* |
| **Topics** | `Array` `Greedy` |

🔗 [View on LeetCode](https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/)

---

## 📋 Problem Description

You are given an integer array `nums` (**0-indexed**). In one operation, you can choose an element of the array and increment it by `1`.




	- For example, if `nums = [1,2,3]`, you can choose to increment `nums[1]` to make `nums = [1,3,3]`.



Return *the **minimum** number of operations needed to make* `nums` ***strictly** **increasing**.*



An array `nums` is **strictly increasing** if `nums[i] < nums[i+1]` for all `0 <= i < nums.length - 1`. An array of length `1` is trivially strictly increasing.



 


**Example 1:**




```
**Input:** nums = [1,1,1]
**Output:** 3
**Explanation:** You can do the following operations:
1) Increment nums[2], so nums becomes [1,1,**2**].
2) Increment nums[1], so nums becomes [1,**2**,2].
3) Increment nums[2], so nums becomes [1,2,**3**].
```


**Example 2:**




```
**Input:** nums = [1,5,2,4,1]
**Output:** 14
```


**Example 3:**




```
**Input:** nums = [8]
**Output:** 0
```


 


**Constraints:**




	- `1 <= nums.length <= 5000`

	- `1 <= nums[i] <= 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cost=0, n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>=nums[i]){
                cost+=(nums[i-1]+1-nums[i]);
                nums[i]=nums[i-1]+1;
            }
        }
        return cost;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** nums[i+1] must be at least equal to nums[i] + 1.

**Hint 2:** Think greedily. You don't have to increase nums[i+1] beyond nums[i]+1.

**Hint 3:** Iterate on i and set nums[i] = max(nums[i-1]+1, nums[i]) .

</details>
