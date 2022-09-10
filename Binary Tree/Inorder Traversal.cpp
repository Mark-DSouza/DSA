#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


// Recursive Solution
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        traversal(root, res);
        return res;
    }
    
    void traversal(TreeNode* root, vector<int> &res) {
        if (!root) return;
        
        traversal(root -> left, res);
        res.push_back(root -> val);
        traversal(root -> right, res);
    }
};


// Iterative Solution
// TC: O(n)
// SC: O(n)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while (curr || !st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr -> left;
            }
            
            curr = st.top(); st.pop();
            res.push_back(curr -> val);
            curr = curr -> right;
        }
        
        return res;
    }
};


// Morris Solution
// TC: O(n)
// SC: O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        TreeNode* curr = root;
        while (curr) {
            if (!curr -> left) {
                res.push_back(curr -> val);
                curr = curr -> right;
            }
            else {
                TreeNode *next = curr -> left;
                while (next -> right) {
                    next = next -> right;
                }
                next -> right = curr;
                
                TreeNode *left = curr -> left;
                curr -> left = nullptr;
                curr = left;
            }
        }
        
        return res;
    }
};