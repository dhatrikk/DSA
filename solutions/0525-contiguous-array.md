# #525 — Contiguous Array

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 31 July 2026 at 02:57 am IST |
| **Runtime** | 15 ms *(beats 95.3%)* |
| **Memory** | 88.4 MB *(beats 44.4%)* |
| **Topics** | `Array` `Hash Table` `Prefix Sum` |

🔗 [View on LeetCode](https://leetcode.com/problems/contiguous-array/)

---

## 📋 Problem Description

Given a binary array `nums`, return *the maximum length of a contiguous subarray with an equal number of *`0`* and *`1`.

 

**Example 1:**

```
**Input:** nums = [0,1]
**Output:** 2
**Explanation:** [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
```

**Example 2:**

```
**Input:** nums = [0,1,0]
**Output:** 2
**Explanation:** [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
```

**Example 3:**

```
**Input:** nums = [0,1,1,1,1,1,0,0,0]
**Output:** 6
**Explanation:** [1,1,1,0,0,0] is the longest contiguous subarray with equal number of 0 and 1.
```

 

**Constraints:**

	- `1 <= nums.length <= 10^5`

	- `nums[i]` is either `0` or `1`.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0, ans=0;
        unordered_map<int,int> mp;
        mp[0]=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            sum+=nums[i];
            if(mp.find(sum)!=mp.end()){
                ans=max(ans,i-mp[sum]);
            }else{
                mp[sum]=i;
            }
        }
        return ans;        
    }
};
```
