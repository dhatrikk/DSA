# #79 — Word Search

| Field | Details |
|---|---|
| **Difficulty** | 🟡 Medium |
| **Language** | C++ |
| **Submitted** | 22 September 2026 at 02:18 pm IST |
| **Runtime** | 215 ms *(beats 64.3%)* |
| **Memory** | 10.5 MB *(beats 65.0%)* |
| **Topics** | `Array` `String` `Backtracking` `Depth-First Search` `Matrix` |

🔗 [View on LeetCode](https://leetcode.com/problems/word-search/)

---

## 📋 Problem Description

Given an `m x n` grid of characters `board` and a string `word`, return `true` *if* `word` *exists in the grid*.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

**Example 1:**

```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
**Output:** true
```

**Example 2:**

```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
**Output:** true
```

**Example 3:**

```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
**Output:** false
```

 

**Constraints:**

	- `m == board.length`

	- `n = board[i].length`

	- `1 <= m, n <= 6`

	- `1 <= word.length <= 15`

	- `board` and `word` consists of only lowercase and uppercase English letters.

 

**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

---

## ✅ Accepted Solution

```cpp
class Solution {
    bool f(vector<vector<char>>& board, string& word, int i, int x, int y, vector<int>& dx, int r, int c){
        if(i==word.size()){
            return true;
        }
        int xx, yy;
        char ch=board[x][y];
        board[x][y]='/';
        for(int j=0;j<4;j++){
            xx=x+dx[j];
            yy=y+dx[3-j];
            if(xx>=0 && yy>=0 && xx<r && yy<c && board[xx][yy]==word[i]){
                if(f(board, word, i+1, xx, yy, dx, r, c)){
                    return true;
                }
            }
        }
        board[x][y]=ch;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size(), c=board[0].size();
        vector<int> dx= {1,-1,0,0};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0]){
                    if(f(board, word, 1, i, j, dx, r, c)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
```
