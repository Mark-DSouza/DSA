/*
  - Kahn's Algorithm is an iterative algorithm to find topological sort of a 
    graph
  - It is preferred over recursive DFS because it detects cycles just by 
    comparing the size of the output and the total number of nodes.
  - It works by counting the indegree of each node and iteratively
    removing the nodes with 0 indegree each round
*/

// Purpose: Topological Sort

// Example Question: Course Schedule(Leetcode)
#include <bits/stdc++.h>
using namespace std;
bool canFinish(int n, vector<vector<int>>& prerequisites) 
{
    vector<vector<int>> graph(n, vector<int>());
    vector<int> indegree(n, 0);
    for (int i = 0; i < prerequisites.size(); i++) {
        int u = prerequisites[i][0], v = prerequisites[i][1];
        graph[v].push_back(u);
        indegree[u]++;
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!indegree[i]) q.push(i);
    }
    
    int count = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        count++;
        
        for (int nbr: graph[v]) {
            if (!--indegree[nbr]) q.push(nbr);
        }
    }
    
    return count == n;
}



// Example Question: 2115. Find All Possible Recipes from Given Supplies (Leetcode)
vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
  unordered_map<string, unordered_set<string>> graph;
  unordered_map<string, int> indegree;
  
  for (string supply: supplies) {
      indegree[supply] = 0;
  }
  
  for (string recipe: recipes) {
      indegree[recipe] = 0;
  }
  
  for (int i = 0; i < ingredients.size(); i++) {
      for (string ingredient: ingredients[i]) {
          graph[ingredient].insert(recipes[i]);
          indegree[recipes[i]]++;
      }
  }
  
  queue<string> q;
  for (pair<string, int> mapping: indegree) {
      if (mapping.second == 0) q.push(mapping.first);
  }
  
  bool firstLevel = true;
  vector<string> res;
  while (!q.empty()) {
      int size = q.size();
      while (size--) {
          string vertex = q.front(); q.pop();
          
          if (!firstLevel) {
              res.push_back(vertex);
          }
          
          for (string nbr: graph[vertex]) {
              if (--indegree[nbr] == 0) q.push(nbr);
          }
      }
      firstLevel = false;
  }
  
  return res;
}

/*
  Important Links
  1) Course Schedule: https://leetcode.com/problems/course-schedule/
  2) 2115. Find All Possible Recipes from Given Supplies: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/ 
*/