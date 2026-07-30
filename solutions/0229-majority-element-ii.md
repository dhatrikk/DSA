# #229 — Majority Element II

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 31 July 2026 at 03:39 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 23.7 MB *(beats 46.4%)* |
| **Topics** | `Array` `Hash Table` `Sorting` `Counting` |

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
        int one=INT_MAX, two=INT_MAX, cnt1=0, cnt2=0;

        for(int i:nums){
            if(i==one){
                cnt1++;
            }else if(i==two){
                cnt2++;
            }else if(cnt1==0 && i!=two){
                one=i;
                cnt1=1;
            }else if(cnt2==0 && i!=one){
                two=i;
                cnt2=1;
            }else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0, cnt2=0;

        for(int i:nums){
            if(i==one){
                cnt1++;
            }
            if(i==two){
                cnt2++;
            }
        }
        int n=nums.size();

        if(cnt1>n/3 && cnt2>n/3){
            return {one, two};
        }
        if(cnt1>n/3){
            return {one};
        }
        if(cnt2>n/3){
            return {two};
        }
        return {};

    }
};


// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> ans;
//         sort(nums.begin(), nums.end());
//         int cnt = 0, num = nums[0];

//         for (int i : nums) {
//             if (i == num) {
//                 cnt++;
//             } else {
//                 if (cnt > n / 3) {
//                     ans.push_back(num);
//                 }
//                 num = i;
//                 cnt = 1;
//             }
//         }
//         if (cnt > n / 3) {
//             ans.push_back(num);
//         }

//         return ans;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Think about the possible number of elements that can appear more than ⌊ n/3 ⌋ times in the array.

**Hint 2:** It can be at most two. Why?

**Hint 3:** Consider using Boyer-Moore Voting Algorithm, which is efficient for finding elements that appear more than a certain threshold.

</details>
