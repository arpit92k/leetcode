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
    int maxdiff = 0;
    int diff;
public:
    int maxAncestorDiff(TreeNode* root) 
    {      
        if(root)
        {
            MaxDiff(root->left, root->val, root->val);
            MaxDiff(root->right, root->val, root->val);
        }
        return maxdiff;
    }
    
    void MaxDiff(TreeNode *node, int maxAncestor, int minAncestor)
    {
        if(node)
        {
            diff = maxAncestor - node->val;
            diff = diff > 0? diff : -diff; 
            if(diff > maxdiff)
            {
                maxdiff = diff;
            }
            diff = minAncestor - node->val;
            diff = diff > 0? diff : -diff;
            if(diff > maxdiff)
            {
                maxdiff = diff;
            }
            maxAncestor = maxAncestor > node->val ? maxAncestor : node->val;
            minAncestor = minAncestor < node->val ? minAncestor : node->val;
            MaxDiff(node->left, maxAncestor, minAncestor);
            MaxDiff(node->right, maxAncestor, minAncestor);
        }
    }
};
