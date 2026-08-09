# #1539 — Kth Missing Positive Number

| Field | Details |
|---|---|
| **Difficulty** | 🟢 Easy |
| **Language** | C++ |
| **Submitted** | 9 August 2026 at 08:37 am IST |
| **Runtime** | 0 ms *(beats 100.0%)* |
| **Memory** | 13.2 MB *(beats 93.2%)* |
| **Topics** | `Array` `Binary Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/kth-missing-positive-number/)

---

## 📋 Problem Description

Given an array `arr` of positive integers sorted in a **strictly increasing order**, and an integer `k`.

Return *the* `k^th` ***positive** integer that is **missing** from this array.*

 

**Example 1:**

```
**Input:** arr = [2,3,4,7,11], k = 5
**Output:** 9
**Explanation: **The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5^th missing positive integer is 9.
```

**Example 2:**

```
**Input:** arr = [1,2,3,4], k = 2
**Output:** 6
**Explanation: **The missing positive integers are [5,6,7,...]. The 2^nd missing positive integer is 6.
```

 

**Constraints:**

	- `1 <= arr.length <= 1000`

	- `1 <= arr[i] <= 1000`

	- `1 <= k <= 1000`

	- `arr[i] < arr[j]` for `1 <= i < j <= arr.length`

 

**Follow up:**

Could you solve this problem in less than O(n) complexity?

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i=0;
        int j=arr.size()-1;
        int ans=-1,m;

        while(i<=j){
            m=i+(j-i)/2;;
            if(arr[m]-(m+1)<k){
                i=m+1;
                ans=m;
            }else{
                j=m-1;
            }
        }
        if(ans==-1){
            return k;
        }
        return (arr[ans]+k-(arr[ans]-(ans+1)));
    }
};


// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         for(int i:arr){
//             if(i<=k){
//                 k++;
//             }else{
//                 break;
//             }
//         }
//         return k;
//     }
// };




// class Solution {
// public:
//     int findKthPositive(vector<int>& arr, int k) {
//         int miss=0;
//         int n=arr.size();
//         int i=0;
//         int num=0;
//         while(i<n && num<=arr[n-1]){
//             num++;
//             if(num==arr[i]){
//                 i++;
//             }else{
//                 miss++;
//             }
//             if(miss==k){
//                 return num;
//             }
//         }

//         return num+(k-miss);
        
//     }
// };
```

---

## 💡 Hints

<details>
<summary>Click to reveal hints</summary>

**Hint 1:** Keep track of how many positive numbers are missing as you scan the array.

</details>
