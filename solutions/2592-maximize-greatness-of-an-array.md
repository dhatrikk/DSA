# #2592 — Maximize Greatness of an Array

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 04:10 am IST |
| **Runtime** | 10 ms *(beats 78.1%)* |
| **Memory** | 80.8 MB *(beats 76.5%)* |
| **Topics** | `Array` `Two Pointers` `Greedy` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/maximize-greatness-of-an-array/)

---

## 📋 Problem Description

You are given a 0-indexed integer array `nums`. You are allowed to permute `nums` into a new array `perm` of your choosing.

We define the **greatness** of `nums` be the number of indices `0  nums[i]`.

Return *the **maximum** possible greatness you can achieve after permuting* `nums`.

 

**Example 1:**

```
**Input:** nums = [1,3,5,2,1,3,1]
**Output:** 4
**Explanation:** One of the optimal rearrangements is perm = [2,5,1,3,3,1,1].
At indices = 0, 1, 3, and 4, perm[i] > nums[i]. Hence, we return 4.
```

**Example 2:**

```
**Input:** nums = [1,2,3,4]
**Output:** 3
**Explanation:** We can prove the optimal perm is [2,3,4,1].
At indices = 0, 1, and 2, perm[i] > nums[i]. Hence, we return 3.
```

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `0 <= nums[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int j=0, ans=0, n=nums.size();
        sort(nums.begin(), nums.end());

        for(int i=0;i<n;i++){
            if(nums[j]<nums[i]){
                j++;
                ans++;
            }
        }
        return ans;
    }
};




// class Solution {
// public:
//     int maximizeGreatness(vector<int>& nums) {
//         map<int,int> mp; 
//         int mx=INT_MIN;
//         for(int i:nums){
//             mp[i]++;
//             mx=max(i, mx);
//         }

//         int ans=0;
//         for(int i:nums){
//             if(i==mx){
//                 continue;
//             }
//             auto it=mp.find(i);
//             it++;
//             while(it->second==0 && it!=mp.end()){
//                 it++;
//             }
//             if(it->second>0){
//                 it->second--;
//                 ans++;
//             }
//         }
//         return ans;
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Can we use sorting and two pointers here?

**Hint 2:** Assign every element the next bigger unused element as many times as possible.

</details>
