# #283 — Move Zeroes

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 04:39 am IST |
| **Runtime** | 6 ms *(beats 43.7%)* |
| **Memory** | 20.5 MB *(beats 55.2%)* |
| **Topics** | `Array` `Two Pointers` |

🔗 [View on LeetCode](https://leetcode.com/problems/move-zeroes/)

---

## 📋 Problem Description

Given an integer array `nums`, move all `0`'s to the end of it while maintaining the relative order of the non-zero elements.

**Note** that you must do this in-place without making a copy of the array.

 

**Example 1:**

```
**Input:** nums = [0,1,0,3,12]
**Output:** [1,3,12,0,0]
```
**Example 2:**

```
**Input:** nums = [0]
**Output:** [0]
```

 

**Constraints:**

	- `1 <= nums.length <= 10^4`

	- `-2^31 <= nums[i] <= 2^31 - 1`

 

**Follow up:** Could you minimize the total number of operations done?

---

## ✅ Accepted Solution

```python
class Solution:
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        ind=0

        for i in range(0, len(nums), 1):
            if(nums[i]!=0):
                tmp=nums[i]
                nums[i]=0
                nums[ind]=tmp
                ind+=1
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** **In-place** means we should not be allocating any space for extra array. But we are allowed to modify the existing array. However, as a first step, try coming up with a solution that makes use of additional space. For this problem as well, first apply the idea discussed using an additional array and the in-place solution will pop up eventually.

**Hint 2:** A **two-pointer** approach could be helpful here. The idea would be to have one pointer for iterating the array and another pointer that just works on the non-zero elements of the array.

</details>
