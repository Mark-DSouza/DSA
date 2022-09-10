/*
  - Idea: Make each character into a box surrounded by 4 dots and then run
    union on each character. Every cycle is one more region
  - Time Complexity: O(n ^ 2) we run union for every character
  - Space Complexity: O(n ^ 2)

  - Link: https://leetcode.com/problems/regions-cut-by-slashes
  - Solution: Pepcoding Youtube Channel
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n(grid.size()), dots(n+1), parent[dots*dots], rank[dots*dots], count(1);
        
        for (int i = 0; i < dots*dots; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
        
        int cell;
        for (int i = 0; i < dots; i++) {
            for (int j = 0; j < dots; j++) {
                if (i == 0 || j == 0 || i == n 
                    || j == n)
                        if ((cell = i * dots + j) != 0)
                            unify(0, cell, parent, rank, count);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    int dot1 = (i+1) * dots + j;
                    int dot2 = i * dots + j + 1;
                    unify(dot1, dot2, parent, rank, count);
                }
                else if (grid[i][j] == '\\') {
                    int dot1 = i * dots + j;
                    int dot2 = (i+1) * dots + j + 1;
                    unify(dot1, dot2, parent, rank, count);
                }
            }
        }
        
        return count;
    }
    
    int find(int x, int parent[]) {
        if (x == parent[x]) return x;
        
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }
    
    void unify(int x, int y, int parent[], int rank[], int& count) {
        int leaderx = find(x, parent);
        int leadery = find(y, parent);
        
        if (leaderx != leadery) {
            if (rank[leaderx] < rank[leadery]) {
                parent[leaderx] = leadery;
            }
            else if (rank[leaderx] > rank[leadery]) {
                parent[leadery] = leaderx;
            }
            else {
                parent[leadery] = leaderx;
                rank[leaderx]++;
            }
        }
        
        else {
            count++;
        }
    }
};