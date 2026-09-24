# #75 — Sort Colors

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 25 September 2026 at 03:08 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 11.8 MB *(beats 11.3%)* |
| **Topics** | `Array` `Two Pointers` `Sorting` `Quicksort` `Bubble Sort` |

🔗 [View on LeetCode](https://leetcode.com/problems/sort-colors/)

---

## 📋 Problem Description

You are given an array `nums` with `n` objects colored red, white, or blue, sort them **in-place **so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

**Example 1:**

**Input:** nums = [2,0,2,1,1,0]

**Output:** [0,0,1,1,2,2]

**Explanation:**

The array has two 0s, two 1s, and two 2s. Sorting them in-place places all 0s first, then all 1s, then all 2s.

**Example 2:**

**Input:** nums = [2,0,1]

**Output:** [0,1,2]

**Explanation:**

The array has one each of 0, 1, and 2, arranged in-place in the order 0, 1, 2.

 

**Constraints:**

	- `n == nums.length`

	- `1 <= n <= 300`

	- `nums[i]` is either 0, 1, or 2.

 

**Follow up:** Could you come up with a one-pass algorithm using only constant extra space?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int z=0, i=0, t=n-1;


        while(i<=t){
            if(nums[i]==2){
                nums[i]=nums[t];
                nums[t]=2;
                t--;
            }else if(nums[i]==0){
                nums[i]=nums[z];
                nums[z]=0;
                z++;
                i++;
            }else{
                i++;
            }
        }
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** A rather straight forward solution is a two-pass algorithm using counting sort.

**Hint 2:** Iterate the array counting number of 0's, 1's, and 2's.

**Hint 3:** Overwrite array with the total number of 0's, then 1's and followed by 2's.

</details>
