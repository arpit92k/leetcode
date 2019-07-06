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
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        if(root && !IsInsufficient(root, 0, limit))
        {
            return root;
        }
        return NULL;
    }
    
    bool IsInsufficient(TreeNode *node, int currentSum, int limit)
    {
        currentSum += node->val;
        
        //for leaf node
        if(node->left == NULL && node->right == NULL)
        {
            if(currentSum < limit)
            {
                return true;
            }
            return false;
        }
        
        //for non-leaf nodes
        bool isLeftInsufficient = true;
        if(node->left)
        {
            isLeftInsufficient = IsInsufficient(node->left, currentSum, limit);    
        }
        bool isRightInsufficient = true;
        if(node->right)
        {
            isRightInsufficient = IsInsufficient(node->right, currentSum, limit);
        }
        
        if(isLeftInsufficient)
        {
            node->left = NULL;
        }
        if(isRightInsufficient)
        {
            node->right = NULL;
        }
        return isLeftInsufficient && isRightInsufficient;
    }
};
