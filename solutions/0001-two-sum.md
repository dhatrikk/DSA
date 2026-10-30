# #1 — Two Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | Python3 |
| **Submitted** | 31 October 2026 at 05:14 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 20.3 MB *(beats 62.8%)* |
| **Topics** | `Array` `Hash Table` |

🔗 [View on LeetCode](https://leetcode.com/problems/two-sum/)

---

## 📋 Problem Description

You are given an array of integers `nums` and an integer `target`, return *indices of the two numbers such that they add up to `target`*.

You may assume that each input would have ***exactly* one solution**, and you may not use the *same* element twice.

You can return the answer in any order.

 

**Example 1:**

**Input:** `nums = [2,7,11,15], target = 9`

**Output:** `[0,1]`

**Explanation:**

The sum of `nums[0]` and `nums[1]` is `2 + 7 = 9`, which equals the target. Therefore, the indices `[0, 1]` are returned.

**Example 2:**

**Input:** `nums = [3,2,4], target = 6`

**Output:** `[1,2]`

**Explanation:**

The sum of `nums[1]` and `nums[2]` is `2 + 4 = 6`, which equals the target. Therefore, the indices `[1, 2]` are returned.

**Example 3:**

**Input:** `nums = [3,3], target = 6`

**Output:** `[0,1]`

**Explanation:**

The sum of `nums[0]` and `nums[1]` is `3 + 3 = 6`, which equals the target. Therefore, the indices `[0, 1]` are returned.

 

**Constraints:**

	- `2  time complexity?

---

## ✅ Accepted Solution

```python
class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:

        mp = dict()

        for i in range(0, len(nums), 1):
            if target-nums[i] in mp:
                return (mp[target-nums[i]], i)
            else:
                mp[nums[i]]=i

        return(-1,-1)
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** A really brute force way would be to search for all possible pairs of numbers but that would be too slow. Again, it's best to try out brute force solutions just for completeness. It is from these brute force solutions that you can come up with optimizations.

**Hint 2:** So, if we fix one of the numbers, say `x`, we have to scan the entire array to find the next number `y` which is `value - x` where value is the input parameter. Can we change our array somehow so that this search becomes faster?

**Hint 3:** The second train of thought is, without changing the array, can we use additional space somehow? Like maybe a hash map to speed up the search?

</details>
