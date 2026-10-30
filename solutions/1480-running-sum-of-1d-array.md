# #1480 — Running Sum of 1d Array

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 04:54 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 19.2 MB *(beats 72.3%)* |
| **Topics** | `Array` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/running-sum-of-1d-array/)

---

## 📋 Problem Description

Given an array `nums`. We define a running sum of an array as `runningSum[i] = sum(nums[0]&hellip;nums[i])`.

Return the running sum of `nums`.

 

**Example 1:**

```
**Input:** nums = [1,2,3,4]
**Output:** [1,3,6,10]
**Explanation:** Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
```

**Example 2:**

```
**Input:** nums = [1,1,1,1,1]
**Output:** [1,2,3,4,5]
**Explanation:** Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
```

**Example 3:**

```
**Input:** nums = [3,1,2,10,1]
**Output:** [3,4,6,16,17]
```

 

**Constraints:**

	- `1 <= nums.length <= 1000`

	- `-10^6 <= nums[i] <= 10^6`

---

## ✅ Accepted Solution

```python
class Solution:
    def runningSum(self, nums: list[int]) -> list[int]:
        
        sum=0
        for i in range(0, len(nums), 1):
            sum+=nums[i]
            nums[i]=sum

        return nums
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think about how we can calculate the i-th number in the running sum from the (i-1)-th number.

</details>
