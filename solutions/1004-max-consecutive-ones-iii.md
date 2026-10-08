# #1004 — Max Consecutive Ones III

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 October 2026 at 02:15 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 79.5 MB *(beats 7.2%)* |
| **Topics** | `Array` `Binary Search` `Sliding Window` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/max-consecutive-ones-iii/)

---

## 📋 Problem Description

Given a binary array `nums` and an integer `k`, return *the maximum number of consecutive *`1`*'s in the array if you can flip at most* `k` `0`'s.

 

**Example 1:**

```
**Input:** nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
**Output:** 6
**Explanation:** [1,1,1,0,0,**1**,1,1,1,1,**1**]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

**Example 2:**

```
**Input:** nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], k = 3
**Output:** 10
**Explanation:** [0,0,1,1,**1**,**1**,1,1,1,**1**,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
```

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `nums[i]` is either 0 or 1.

	- `0 <= k <= nums.length`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans=0, zero=0;
        int l=0, r=0;
        while(r<nums.size()){
            if(nums[r]==0){
                zero++;
            }
            while(zero>k){
                if(nums[l]==0){
                    zero--;
                }
                l++;
            }
            ans=max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** One thing's for sure, we will only flip a zero if it extends an existing window of 1s. Otherwise, there's no point in doing it, right? Think Sliding Window!

**Hint 2:** Since we know this problem can be solved using the sliding window construct, we might as well focus in that direction for hints. Basically, in a given window, we can never have > K zeros, right?

**Hint 3:** We don't have a fixed size window in this case. The window size can grow and shrink depending upon the number of zeros we have (we don't actually have to flip the zeros here!).

**Hint 4:** The way to shrink or expand a window would be based on the number of zeros that can still be flipped and so on.

</details>
