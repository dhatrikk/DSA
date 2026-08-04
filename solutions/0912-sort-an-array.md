# #912 — Sort an Array

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 4 August 2026 at 08:30 pm IST |
| **Runtime** | 651 ms *(beats 24.0%)* |
| **Memory** | 295.7 MB *(beats 23.0%)* |
| **Topics** | `Array` `Divide and Conquer` `Sorting` `Heap (Priority Queue)` `Merge Sort` `Bucket Sort` `Radix Sort` `Counting Sort` |

🔗 [View on LeetCode](https://leetcode.com/problems/sort-an-array/)

---

## 📋 Problem Description

Given an array of integers `nums`, sort the array in ascending order and return it.

You must solve the problem **without using any built-in** functions in `O(nlog(n))` time complexity and with the smallest space complexity possible.

 

**Example 1:**

```
**Input:** nums = [5,2,3,1]
**Output:** [1,2,3,5]
**Explanation:** After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).
```

**Example 2:**

```
**Input:** nums = [5,1,1,2,0,0]
**Output:** [0,0,1,1,2,5]
**Explanation:** Note that the values of nums are not necessarily unique.
```

 

**Constraints:**

	- `1 <= nums.length <= 5 * 10^4`

	- `-5 * 10^4 <= nums[i] <= 5 * 10^4`

---

## ✅ Accepted Solution

```cpp
class Solution {
    void mrg(vector<int>& nums, int i, int mid, int j){
        vector<int> tmp;
        int l=i, r=mid+1;
        while(l<=mid && r<=j){
            if(nums[l]<=nums[r]){
                tmp.push_back(nums[l]);
                l++;
            }else{
                tmp.push_back(nums[r]);
                r++;
            }
        }
        while(l<=mid){
            tmp.push_back(nums[l]);
            l++;
        }
        while(r<=j){
            tmp.push_back(nums[r]);
            r++;
        }
        for(int x=i;x<=j;x++){
            nums[x]=tmp[x-i];
        }
        return;
    }
    void srt(vector<int>& nums, int i, int j){
        if(i>=j){
            return;
        }
        int mid=(i+j)/2;
        srt(nums, i, mid);
        srt(nums, mid+1, j);
        mrg(nums, i, mid, j);
        return;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        srt(nums, 0, nums.size()-1);
        return nums;
    }
};
```
