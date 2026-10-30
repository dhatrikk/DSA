# #238 — Product of Array Except Self

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 04:34 am IST |
| **Runtime** | 16 ms *(beats 86.7%)* |
| **Memory** | 24.7 MB *(beats 99.5%)* |
| **Topics** | `Array` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/product-of-array-except-self/)

---

## 📋 Problem Description

Given an integer array `nums`, return *an array* `answer` *such that* `answer[i]` *is equal to the product of all the elements of* `nums` *except* `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

 

**Example 1:**

```
**Input:** nums = [1,2,3,4]
**Output:** [24,12,8,6]
```
**Example 2:**

```
**Input:** nums = [-1,1,0,-3,3]
**Output:** [0,0,9,0,0]
```

 

**Constraints:**

	- `2 <= nums.length <= 10^5`

	- `-30 <= nums[i] <= 30`

	- The input is generated such that `answer[i]` is **guaranteed** to fit in a **32-bit** integer.

 

**Follow up:** Can you solve the problem in `O(1)` extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

---

## ✅ Accepted Solution

```python
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        zero=0
        ind=-1
        pro=1

        for i in range(len(nums)):
            if nums[i]==0:
                zero+=1
                ind=i
            else:
                pro = pro * nums[i]    

        if zero==0:
            for i in range(0, len(nums), 1):
                nums[i] = pro//nums[i]
        elif zero==1:
            for i in range(0, len(nums), 1):
                nums[i] = 0
            nums[ind]=pro    
        else:
            for i in range(0, len(nums), 1):
                nums[i] = 0    

        return nums
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think how you can efficiently utilize prefix and suffix products to calculate the product of all elements except self for each index. Can you pre-compute the prefix and suffix products in linear time to avoid redundant calculations?

**Hint 2:** Can you minimize additional space usage by reusing memory or modifying the input array to store intermediate results?

</details>
