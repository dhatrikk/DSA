# #128 — Longest Consecutive Sequence

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 06:04 pm IST |
| **Runtime** | 80 ms *(beats 58.5%)* |
| **Memory** | 89.1 MB *(beats 25.7%)* |
| **Topics** | `Array` `Hash Table` `Union-Find` |

🔗 [View on LeetCode](https://leetcode.com/problems/longest-consecutive-sequence/)

---

## 📋 Problem Description

Given an unsorted array of integers `nums`, return *the length of the longest consecutive elements sequence.*

You must write an algorithm that runs in `O(n)` time.

 

**Example 1:**

```
**Input:** nums = [100,4,200,1,3,2]
**Output:** 4
**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore its length is 4.
```

**Example 2:**

```
**Input:** nums = [0,3,7,2,5,8,4,6,0,1]
**Output:** 9
```

**Example 3:**

```
**Input:** nums = [1,0,1,2]
**Output:** 3
```

 

**Constraints:**

	- `0 <= nums.length <= 10^5`

	- `-10^9 <= nums[i] <= 10^9`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        unordered_set<int> s;
        for(int i:nums){
            s.insert(i);
        }
        int ans=1, cnt;
        for(int i:s){
            if(s.find(i-1)==s.end()){
                int n=i+1;
                cnt=1;
                while(s.find(n)!=s.end()){
                    cnt++;
                    n++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     int longestConsecutive(vector<int>& nums) {
//         int cnt=1, n=nums.size(), ans=1;

//         if(n==0){
//             return 0;
//         }

//         sort(nums.begin(), nums.end());

//         for(int i=1;i<n;i++){
//             if(nums[i]==nums[i-1]+1){
//                 cnt++;
//             }else if(nums[i]==nums[i-1]){

//             }else{
//                 cnt=1;
//             }
//             ans=max(ans, cnt);
//         }
//         return ans;
//     }
// };
```
