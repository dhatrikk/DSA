# #645 — Set Mismatch

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 8 October 2026 at 09:00 pm IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 25.2 MB *(beats 75.2%)* |
| **Topics** | `Array` `Hash Table` `Bit Manipulation` `Sorting` |

🔗 [View on LeetCode](https://leetcode.com/problems/set-mismatch/)

---

## 📋 Problem Description

You have a set of integers `s`, which originally contains all the numbers from `1` to `n`. Unfortunately, due to some error, one of the numbers in `s` got duplicated to another number in the set, which results in **repetition of one** number and **loss of another** number.

You are given an integer array `nums` representing the data status of this set after the error.

Find the number that occurs twice and the number that is missing and return *them in the form of an array*.

 

**Example 1:**

```
**Input:** nums = [1,2,2,4]
**Output:** [2,3]
```
**Example 2:**

```
**Input:** nums = [1,1]
**Output:** [1,2]
```

 

**Constraints:**

	- `2 <= nums.length <= 10^4`

	- `1 <= nums[i] <= 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int xr=0, n=nums.size();
        for(int i=0;i<n;i++){
            xr^=(i+1);
            xr^=nums[i];
        }

        int df=0;
        for(int i=0;1;i++){
            if(1<<i & xr){
                df=i;
                break;
            }
        }
        cout<<df;
        int x=0;

        for(int i=0;i<n;i++){
            if(nums[i] & 1<<df){
                x^=nums[i];
            }
            if(i+1 & 1<<df){
                x^=(i+1);
            }
        }

        xr^=x;
        for(int i:nums){
            if(xr==i){
                return {xr, x};
            }
        }

        return {x, xr};

    }
};




// class Solution {
// public:
//     vector<int> findErrorNums(vector<int>& nums) {
//         int n=nums.size();
//         int act = (n * (n+1))/2;
//         long long actsq = (((1LL*n*(n+1))/2)*(2*n +1))/3;
//         int a,b;
//         int sum=0;
//         long long sq=0;

//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             sq+=(nums[i]*nums[i]);
//         }
//         int diff=sum - act;
//         int sqdiff= sq - actsq;
//         b = ((sqdiff/ diff) - diff)/2;
//         a = diff + b;
//         return {a,b};
//     }
// };
```
