/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        TreeNode* n1 = root->left;
        TreeNode* n2 = root->right;
        return checkMirror(n1, n2);
        
    }
    
    bool checkMirror(TreeNode* n1, TreeNode* n2)
    {
        if(n1 && n2 &&n1->val == n2->val)
        {
            return checkMirror(n1->left, n2->right) && checkMirror(n1->right, n2->left);
        }
        else if(!n1 && !n2)
        {
            return true;
        }
        return false;
    }
};
