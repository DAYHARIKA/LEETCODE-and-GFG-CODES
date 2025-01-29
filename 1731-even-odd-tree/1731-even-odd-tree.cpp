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
    bool isEvenOddTree(TreeNode* root) {
         if(!root)return true;
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
     while(!q.empty())
     {
        int s=q.size();
        vector<int>t;
        for(int i=0;i<s;++i)
        {
            TreeNode* x=q.front();
            q.pop();
            t.push_back(x->val);
            if(x->left)q.push(x->left);
            if(x->right)q.push(x->right);
        }
        if(level%2==0)
        {
            for(int val:t)
            {
                if(val%2==0)return false;
            }
            for(int i=1;i<t.size();++i)
            {
                if(t[i]<=t[i-1])return false;
            }
        }
            else{
                for(int val:t)
                {
                    if(val%2!=0)return false;
                }
                for(int i=1;i<t.size();++i){
                    if(t[i]>=t[i-1])return false;
                }
            }
            ++level;
        }
        return true;
    }
};