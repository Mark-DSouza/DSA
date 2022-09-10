/*
    - Idea: Sort the edges in desceding order to deal with the 
        common edges first
    - Remember to do the recursion properly in the find function
    - Remember to do the all comparisons with only the leaders in unify

    - Time Complexity: O(n + edges.size())
    - Space Complexity: O(n)

    - Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        int parentA[n+1], parentB[n+1], rankA[n+1], rankB[n+1],
            mergedA(1), mergedB(1), removed(0);
        
        for (int i = 0; i <= n; i++) {
            parentA[i] = i;
            parentB[i] = i;
            rankA[i] = 1;
            rankB[i] = 1;
        }
        
        sort(edges.begin(), 
             edges.end(), 
             [](vector<int>& a, vector<int>& b) -> bool {
                 return a[0] > b[0];
             });

        for (vector<int> edge: edges) {
            int type(edge[0]), x(edge[1]), y(edge[2]);

            if (type == 3) {
                bool isUnifiedA = unify(x, y, parentA, rankA);
                bool isUnifiedB = unify(x, y, parentB, rankB);
                
                mergedA += isUnifiedA;
                mergedB += isUnifiedB;
                removed += (!isUnifiedA && !isUnifiedB);
            }
            else if (type == 1) {
                bool isUnifiedA = unify(x, y, parentA, rankA);
                mergedA += isUnifiedA;
                removed += !isUnifiedA;
            }
            else {
                bool isUnifiedB = unify(x, y, parentB, rankB);
                mergedB += isUnifiedB;
                removed += !isUnifiedB;
            }
        }
        
        if (mergedA != n || mergedB != n)
            return -1;
        return removed;  
    }
    
    int find(int x, int parent[]) {
        if (parent[x] == x) 
            return x;
        
        int temp = find(parent[x], parent);
        parent[x] = temp;
        return temp;
    }
    
    bool unify(int x, int y, int parent[], int rank[]) {
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
                parent[leaderx] = leadery;
                rank[leadery]++;
            }
            return true;
        }
        
        return false;
    }
};