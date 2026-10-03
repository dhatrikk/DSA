# #126 — Word Ladder II

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 3 October 2026 at 10:18 am IST |
| **Runtime** | 5 ms *(beats 97.2%)* |
| **Memory** | 15 MB *(beats 7.4%)* |
| **Topics** | `Hash Table` `String` `Backtracking` `Breadth-First Search` `Bidirectional Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/word-ladder-ii/)

---

## 📋 Problem Description

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s_1 -> s_2 -> ... -> s_k` such that:

	- Every adjacent pair of words differs by a single letter.

	- Every `s_i` for `1  "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
```

**Example 2:**

```
**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
**Output:** []
**Explanation:** The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

 

**Constraints:**

	- `1 <= beginWord.length <= 5`

	- `endWord.length == beginWord.length`

	- `1 <= wordList.length <= 500`

	- `wordList[i].length == beginWord.length`

	- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.

	- `beginWord != endWord`

	- All the words in `wordList` are **unique**.

	- The **sum** of all shortest transformation sequences does not exceed `10^5`.

---

## ✅ Accepted Solution

```cpp
class Solution {
    void f(vector<vector<string>>& ans, string word, string target,
           unordered_map<int, unordered_set<string>>& mp, vector<string> curr, int lvl) {
        curr.push_back(word);
        if (word == target) {
            reverse(curr.begin(), curr.end());
            ans.push_back(curr);
            return;
        }
        string tmp;
        for (int i = 0; i < word.size(); i++) {
            tmp = word;
            for (char c = 'a'; c <= 'z'; c++) {
                tmp[i] = c;
                if (mp[lvl].find(tmp) != mp[lvl].end()) {
                    f(ans, tmp, target, mp, curr, lvl - 1);
                }
            }
        }
        curr.pop_back();
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) {
            return {};
        }
        unordered_map<int, unordered_set<string>> mp;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        mp[1].insert(beginWord);
        string node, tmp;
        int lvl, mx = INT_MAX;

        while (!q.empty()) {
            node = q.front().first;
            lvl = q.front().second;
            if (lvl == mx) {
                break;
            }
            q.pop();

            for (int i = 0; i < beginWord.size(); i++) {
                tmp = node;
                for (char c = 'a'; c <= 'z'; c++) {
                    tmp[i] = c;
                    if (st.find(tmp) != st.end()) {
                        q.push({tmp, lvl + 1});
                        mp[lvl + 1].insert(tmp);
                        st.erase(tmp);
                        if (tmp == endWord) {
                            mx = lvl + 1;
                        }
                    }
                }
            }
        }

        vector<vector<string>> ans;
        f(ans, endWord, beginWord, mp, {}, mx - 1);

        return ans;
    }
};



// MLE
// class Solution {
// public:
//     vector<vector<string>> findLadders(string beginWord, string endWord,
//     vector<string>& wordList) {
//         unordered_set<string> s(wordList.begin(), wordList.end());
//         if (s.find(endWord) == s.end()) {
//             return {};
//         }

//         queue<vector<string>> q;
//         q.push({beginWord});

//         int n = beginWord.size(), sz;
//         vector<string> tobe, node;
//         bool cntn = true;
//         string word;

//         while (!q.empty() && !s.empty() && cntn) {
//             sz = q.size();
//             for (int i = 0; i < sz; i++) {
//                 node = q.front();
//                 q.pop();

//                 for (int j = 0; j < n; j++) {
//                     word = node[node.size() - 1];
//                     for (char c = 'a'; c <= 'z'; c++) {
//                         word[j] = c;
//                         if (s.find(word) != s.end()) {
//                             if (word == endWord) {
//                                 cntn = false;
//                             }
//                             tobe.push_back(word);
//                             node.push_back(word);
//                             q.push(node);
//                             node.pop_back();
//                         }
//                     }
//                 }
//             }
//             if(!cntn){
//                 break;
//             }
//             for (auto it : tobe) {
//                 s.erase(it);
//             }
//             tobe={};
//         }
//         vector<vector<string>> ans;
//         while (!q.empty()) {
//             node = q.front();
//             if (node[node.size() - 1] == endWord) {
//                 ans.push_back(node);
//             }
//             q.pop();
//         }
//         return ans;
//     }
// };
```
