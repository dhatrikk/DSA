# #88 — Merge Sorted Array

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 31 July 2026 at 04:04 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 12.5 MB *(beats 8.7%)* |
| **Topics** | `Array` `Two Pointers` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/merge-sorted-array/)

---

## 📋 Problem Description

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in **non-decreasing order**.

The final sorted array should not be returned by the function, but instead be *stored inside the array *`nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

 

**Example 1:**

```
**Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
**Output:** [1,2,2,3,5,6]
**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.
```

**Example 2:**

```
**Input:** nums1 = [1], m = 1, nums2 = [], n = 0
**Output:** [1]
**Explanation:** The arrays we are merging are [1] and [].
The result of the merge is [1].
```

**Example 3:**

```
**Input:** nums1 = [0], m = 0, nums2 = [1], n = 1
**Output:** [1]
**Explanation:** The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
```

 

**Constraints:**

	- `nums1.length == m + n`

	- `nums2.length == n`

	- `0 <= m, n <= 200`

	- `1 <= m + n <= 200`

	- `-10^9 <= nums1[i], nums2[j] <= 10^9`

 

**Follow up: **Can you come up with an algorithm that runs in `O(m + n)` time?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int n1, vector<int>& nums2, int n2) {
        int k=n1+n2-1;
        n1--;
        n2--;

        while(n1>=0 && n2>=0){
            if(nums1[n1]>nums2[n2]){
                nums1[k]=nums1[n1];
                nums1[n1]=0;
                n1--;
                k--;
            }else{
                nums1[k]=nums2[n2];
                n2--;
                k--;
            }
        }
            if(k>=0){
                while(n2>=0){
                nums1[k]=nums2[n2];
                k--;
                n2--;
            }
            }
        }   
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** You can easily solve this problem if you simply think about two elements at a time rather than two arrays. We know that each of the individual arrays is sorted. What we don't know is how they will intertwine. Can we take a local decision and arrive at an optimal solution?

**Hint 2:** If you simply consider one element each at a time from the two arrays and make a decision and proceed accordingly, you will arrive at the optimal solution.

</details>
