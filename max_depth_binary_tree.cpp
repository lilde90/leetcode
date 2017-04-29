// Copyright 2017 lilde90. All Rights Reserved.
// Author: Pan Li (panli.me@gmail.com)
//
/**
 *  * Definition for a binary tree node.
 *   * struct TreeNode {
 *    *     int val;
 *     *     TreeNode *left;
 *      *     TreeNode *right;
 *       *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *        * };
 *         */
class Solution {
public:
  int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      }
                         
      if (root->left == NULL) {
        return 1 + maxDepth(root->right);
      }
                                 
      if (root->right == NULL) {
        return 1 + maxDepth(root->left);
      }
      return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
  }
};
