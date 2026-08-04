# #645 — Set Mismatch

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 4 August 2026 at 05:58 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 25.1 MB *(beats 88.5%)* |
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
        int xo=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            xo=xo^nums[i];
            xo=xo^(i+1);
        }
        int bit=0;
        while(1){
            if((xo & (1<<bit)) != 0 ){
                break;
            }
            bit++;
        }

        int a=0, b=0;
        for(int i=0;i<n;i++){
            if(nums[i] & (1<<bit)){
                a=a^nums[i];
            }else{
                b=b^nums[i];
            }
            if((i+1) & (1<<bit)){
                a=a^(i+1);
            }else{
                b=b^(i+1);
            }
        }
        int cnt=0;
        for(int i:nums){
            if(i==a){
                cnt++;
            }
        }
        if(cnt==2){
            return {a,b};
        }
        return {b,a};
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
