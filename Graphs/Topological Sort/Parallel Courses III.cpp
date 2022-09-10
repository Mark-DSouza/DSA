/*
  - Idea: Find the maximum time to complete each course instead of findthe maximum at each level
  - Idea: To get the answer take the maximum of the tim eit takes to do each course.
  - Time Complexity: O(N(vertices/courses) + M(edges))
  - Space Complexity: O(N + M) + O(N) + (N) = O(N + M)
  - Link: https://leetcode.com/problems/parallel-courses-iii
*/

#include <bits/stdc++.h>
using namespace std;
int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<vector<int>> graph(n+1, vector<int>());
    vector<int> indegree(n+1, 0), maxTime(n+1, 0);
    
    for (int i = 0; i < relations.size(); i++) {
        int u = relations[i][0], v = relations[i][1];
        graph[u].push_back(v);
        indegree[v]++;
    }
    
    queue<int> q;
    for (int i = 1; i < indegree.size(); i++) {
        if (!indegree[i]) {
            q.push(i);
            maxTime[i] = time[i-1];                
        }
    }
    
    int res(0);
    while (!q.empty()) {
        int size(q.size());
        while (size--) {
            int vertex = q.front(); q.pop();
            
            for (int nbr: graph[vertex]) {
                maxTime[nbr] = max(maxTime[nbr], time[nbr-1] + maxTime[vertex]);
                if (--indegree[nbr] == 0)
                    q.push(nbr);
            }
        }
    }
    
    for (int i = 0; i < maxTime.size(); i++) {
        cout << maxTime[i] << " ";
    }
    return *max_element(maxTime.begin(), maxTime.end());
}