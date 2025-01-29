/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void collectleafvalues(TreeNode*root,vector<int>&x)
    {
        if(!root)return;
            if(!root->left&&!root->right){
                x.push_back(root->val);
                return;
            }
             collectleafvalues(root->left,x);
             collectleafvalues(root->right,x);
            
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>res1,res2;
        collectleafvalues(root1,res1);
        collectleafvalues(root2,res2);
        return res1==res2;
    }
};