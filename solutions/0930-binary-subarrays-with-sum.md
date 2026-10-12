# #930 — Binary Subarrays With Sum

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 12 October 2026 at 11:24 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 33.4 MB *(beats 38.3%)* |
| **Topics** | `Array` `Hash Table` `Sliding Window` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/binary-subarrays-with-sum/)

---

## 📋 Problem Description

Given a binary array `nums` and an integer `goal`, return *the number of non-empty **subarrays** with a sum* `goal`.

A **subarray** is a contiguous part of the array.

 

**Example 1:**

```
**Input:** nums = [1,0,1,0,1], goal = 2
**Output:** 4
**Explanation:** The 4 subarrays are bolded and underlined below:
[**1,0,1**,0,1]
[**1,0,1,0**,1]
[1,**0,1,0,1**]
[1,0,**1,0,1**]
```

**Example 2:**

```
**Input:** nums = [0,0,0,0,0], goal = 0
**Output:** 15
```

 

**Constraints:**

	- `1 <= nums.length <= 3 * 10^4`

	- `nums[i]` is either `0` or `1`.

	- `0 <= goal <= nums.length`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        vector<int> ind;
        int n = nums.size();
        ind.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (nums[i]) {
                ind.push_back(i);
            }
        }
        ind.push_back(n);
        int s = ind.size(), ans = 0;
        if (k == 0) {
            for (int i = 1; i < s; i++) {
                int m = ind[i] - ind[i - 1] - 1;
                ans += (m * (m + 1)) / 2;
            }
        } else {
            for (int r = k; r < s - 1; r++) {
                ans += ((ind[r - k + 1] - ind[r - k]) * (ind[r + 1] - ind[r]));
            }
        }

        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Can you transform the problem into finding two prefix sums whose difference equals `goal`?

**Hint 2:** While iterating through the array, keep track of how many times each prefix sum has appeared so far.

**Hint 3:** If the current prefix sum is `curr`, how many previous prefix sums equal to `curr - goal` exist?

</details>
