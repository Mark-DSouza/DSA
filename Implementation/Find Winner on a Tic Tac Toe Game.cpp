#include <bits/stdc++.h>
using namespace std;


// Brute Force
// Idea: For each move made, we add it to a grid and then check if its row, column, diagonal(row == col) or antidiagonal(row + col == n-1) are winning.
// TC: O(moves * n)
// SC: O(n * n)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3, player = 1;
        vector<vector<int>> grid(n, vector<int>(n, 0));
        
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            
            grid[row][col] = player;
            if (
                checkRow(grid, row, player) or 
                checkCol(grid, col, player) or
                (row == col and checkDiagonal(grid, player)) or
                (row + col == n-1 and checkAntidiagonal(grid, player))
            ) {
                return player == 1 ? "A" : "B"; 
            }
                
            player = -player;
        }
                
        return moves.size() == n * n ? "Draw": "Pending";
    }
    
    bool checkRow(vector<vector<int>> &grid, int row, int player) {
        for (int col = 0; col < grid.size(); col++) {
            if (grid[row][col] != player) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkCol(vector<vector<int>> &grid, int col, int player) {
        for (int row = 0; row < grid.size(); row++) {
            if (grid[row][col] != player) {
                return false;
            }
        }
        
        return true;
    }
    
    bool checkDiagonal(vector<vector<int>> &grid, int player) {
        for (int i = 0; i < grid.size(); i++) {
            if (grid[i][i] != player) {
                return false;
            } 
        }
        
        return true;
    }
    
    bool checkAntidiagonal(vector<vector<int>> &grid, int player) {
        int n = grid.size();
        for (int i = 0; i < n; i++) {
            if (grid[i][n-1-i] != player) {
                return false;
            }
        }
        
        return true;
    }
};


// Optimised Approach
// Idea:
// We don't need to maintain the entire grid. All we need is a way to track if the current row/column is winning or not. We can achieve this by maintaining the sum of moves made by the players i.e. +1 for player A and -1 for player B.
// TC: O(moves)
// SC: O(n)
class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int n = 3, player = 1;
        vector<int> rows(n), cols(n);
        int diagonal = 0, antidiagonal = 0;
        
        for (int i = 0; i < moves.size(); i++) {
            int row = moves[i][0];
            int col = moves[i][1];
            
            rows[row] += player;
            cols[col] += player;
            if (row == col) diagonal += player;
            if (row + col == n-1) antidiagonal += player;
            
            if (abs(rows[row]) == n or 
                abs(cols[col]) == n or 
                abs(diagonal) == n or 
                abs(antidiagonal) == n) {
                return player == 1 ? "A" : "B";
            }
            
            player = -player;
        }
        
        return moves.size() == n * n ? "Draw" : "Pending";
    }
};