# #127 — Word Ladder

| Field | Details |
|---|---|
| **Difficulty** | 🔴 Hard |
| **Language** | C++ |
| **Submitted** | 3 October 2026 at 06:06 am IST |
| **Runtime** | 51 ms *(beats 73.5%)* |
| **Memory** | 21.1 MB *(beats 70.1%)* |
| **Topics** | `Hash Table` `String` `Breadth-First Search` `Bidirectional Search` |

🔗 [View on LeetCode](https://leetcode.com/problems/word-ladder/)

---

## 📋 Problem Description

A **transformation sequence** from word `beginWord` to word `endWord` using a dictionary `wordList` is a sequence of words `beginWord -> s_1 -> s_2 -> ... -> s_k` such that:

	- Every adjacent pair of words differs by a single letter.

	- Every `s_i` for `1  "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
```

**Example 2:**

```
**Input:** beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
**Output:** 0
**Explanation:** The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
```

 

**Constraints:**

	- `1 <= beginWord.length <= 10`

	- `endWord.length == beginWord.length`

	- `1 <= wordList.length <= 5000`

	- `wordList[i].length == beginWord.length`

	- `beginWord`, `endWord`, and `wordList[i]` consist of lowercase English letters.

	- `beginWord != endWord`

	- All the words in `wordList` are **unique**.

---

## ✅ Accepted Solution

```cpp
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s(wordList.begin(), wordList.end());
        if(s.find(endWord)==s.end()){
            return 0;
        }
        queue<pair<string, int>> q;
        int n=beginWord.size(), level;
        q.push({beginWord, 1});
        string node, tmp;


        while(!q.empty()){
            node = q.front().first;
            level = q.front().second;
            q.pop();
            for(int i=0;i<n;i++){
                tmp=node;
                for(char c='a';c<='z';c++){
                    tmp[i]=c;
                    if(s.find(tmp)!=s.end()){
                        if(tmp==endWord){
                            return level+1;
                        }else{
                            q.push({tmp, level+1});
                            s.erase(tmp);
                        }   
                    }
                }
            }
        }

        return 0;
    }
};
```
