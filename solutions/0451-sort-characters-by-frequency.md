# #451 — Sort Characters By Frequency

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 5 August 2026 at 04:37 pm IST |
| **Runtime** | 64 ms *(beats 5.3%)* |
| **Memory** | 10.4 MB *(beats 95.9%)* |
| **Topics** | `Hash Table` `String` `Sorting` `Heap (Priority Queue)` `Bucket Sort` `Counting` |

🔗 [View on LeetCode](https://leetcode.com/problems/sort-characters-by-frequency/)

---

## 📋 Problem Description

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return *the sorted string*. If there are multiple answers, return *any of them*.

 

**Example 1:**

```
**Input:** s = "tree"
**Output:** "eert"
**Explanation:** 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```
**Input:** s = "cccaaa"
**Output:** "aaaccc"
**Explanation:** Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```
**Input:** s = "Aabb"
**Output:** "bbAa"
**Explanation:** "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

 

**Constraints:**

	- `1 <= s.length <= 5 * 10^5`

	- `s` consists of uppercase and lowercase English letters and digits.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char c:s){
            freq[c]++;
        }

        sort(s.begin(), s.end(), [&](char a, char b){
            if(freq[a]==freq[b]){
                return a>b;
            }
            return freq[a]>freq[b];
        });
        return s;
    }
};


// class Solution {
// public:
//     string frequencySort(string s) {
//         map<char,int> mm;
//         for(char& c:s){
//             mm[c]++;
//         }
//         vector<pair<int,char>> mp;
//         for(auto it:mm){
//             mp.push_back({it.second, it.first});
//         }
//         sort(mp.begin(), mp.end(), greater<pair<int,char>>());
//         s="";
//         for(auto it:mp){
//             int x=it.first;
//             char c=it.second;
//             while(x){
//                 s+=c;
//                 x--;
//             }
//         }
//         return s;

//     }
// };
```
