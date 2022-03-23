// Leetcode 79 Word Search -Medium

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.

// The word can be constructed from letters of sequentially adjacent cells, 
// where adjacent cells are horizontally or vertically neighboring. 
// The same letter cell may not be used more than once.

#include <vector>
#include <string>
using namespace std;


class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(dfs(board,i,j,word,0)) return true;
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int k){
        if(i < 0 || i >= board.size() || j < 0 
            || j >= board[0].size() || board[i][j] != word[k]){
            return false;
        }

        if(k == word.length()-1)    return true;

        // vector<vector<char>> temp = board;
        board[i][j] = '#';
        bool res = dfs(board, i-1, j, word, k+1) 
        || dfs(board, i+1, j, word, k+1)
        || dfs(board, i, j-1, word, k+1) 
        || dfs(board, i, j+1, word, k+1);
        
        board[i][j] = word[k];
        return res;
    }
};