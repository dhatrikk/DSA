# #229 — Majority Element II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 26 September 2026 at 12:48 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 23.9 MB *(beats 55.2%)* |
| **Topics** | `Array` `Hash Table` `Sorting` `Counting` `Boyer–Moore Majority Vote Algorithm` |

🔗 [View on LeetCode](https://leetcode.com/problems/majority-element-ii/)

---

## 📋 Problem Description

Given an integer array of size `n`, find all elements that appear more than `&lfloor;n / 3&rfloor;` times.

 

**Example 1:**

```
**Input:** nums = [3,2,3]
**Output:** [3]
```

**Example 2:**

```
**Input:** nums = [1]
**Output:** [1]
```

**Example 3:**

```
**Input:** nums = [1,2]
**Output:** [1,2]
```

 

**Constraints:**

	- `1 <= nums.length <= 5 * 10^4`

	- `-10^9 <= nums[i] <= 10^9`

 

**Follow up:** Could you solve the problem in linear time and in `O(1)` space?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int n = nums.size();
        int num1 =nums[0], num2=0;

        for (int i : nums) {
            if (i == num1 || (cnt1==0 && i!=num2)) {
                if(cnt1==0 && i!=num2){
                    cnt1=0;
                    num1=i;
                }
                cnt1++;
            } else if (i == num2 || (cnt2==0 && i!=num1)) {
                if(cnt2==0 && i!=num1){
                    cnt2=0;
                    num2=i;
                }
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }            
        }

        cnt1 = 0, cnt2 = 0;
        for (int i : nums) {
            if (i == num1) {
                cnt1++;
            } else if (i == num2) {
                cnt2++;
            }
        }
        if (cnt1 > n / 3 && cnt2 > n / 3) {
            return {num1, num2};
        } else if (cnt1 > n / 3) {
            return {num1};
        } else if (cnt2 > n / 3) {
            return {num2};
        }
        return {};
    }
};
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think about the possible number of elements that can appear more than ⌊ n/3 ⌋ times in the array.

**Hint 2:** It can be at most two. Why?

**Hint 3:** Consider using Boyer-Moore Voting Algorithm, which is efficient for finding elements that appear more than a certain threshold.

</details>
