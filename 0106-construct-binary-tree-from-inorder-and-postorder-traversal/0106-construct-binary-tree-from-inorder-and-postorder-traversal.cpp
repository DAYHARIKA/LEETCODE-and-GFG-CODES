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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder,unordered_map<int,int> &mp,int &postindex,int instart,int inend,int n){

           //basecase

           if(postindex < 0 || instart > inend){
             return NULL;
           }

           int element = postorder[postindex--];
           TreeNode* temp=new TreeNode(element);
           //find the position of postoder element in inorder vector
          // int position=find_pos(inorder,instart,inend,element);
           int position=mp[element];

           //recursioncalls
           temp->right=solve(postorder,inorder,mp,postindex,position+1,inend,n);
           temp->left=solve(postorder,inorder,mp,postindex,instart,position-1,n);

           return temp;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int n = inorder.size();
        int postorderindex=n-1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(postorder,inorder,mp,postorderindex,0,n-1,n);
        return root;  
    }
};