// If root is smaller than p and q, move right
// If root is greater than p and q, move left
// Else return root

// If the traversal is a single height traversal, then do it iteratively for better TC

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Recursive Approach
// TC: O(N)
// SC: O(N)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  int pVal = p -> val, qVal = q -> val, rootVal = root -> val;
  
  if (rootVal < pVal && rootVal < qVal) {
    return lowestCommonAncestor(root -> right, p, q);
  }
  
  else if (rootVal > pVal && rootVal > qVal) {
    return lowestCommonAncestor(root -> left, p, q);
  }
  
  return root;
}

// Iterative Approach
// TC: O(N)
// SC: O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  int pVal = p -> val, qVal = q -> val;
  while (root) {
    int rootVal = root -> val;
    if (rootVal < pVal && rootVal < qVal) {
      root = root -> right;
    }
    else if (rootVal > pVal && rootVal > qVal) {
        root = root -> left;
    }
    
    else {
        break;
    }
  }
  
  return root; 
} 