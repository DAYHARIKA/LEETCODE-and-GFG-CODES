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
    /*int find_pos(vector<int>& inorder,int instart,int inend,int element){
       
       for(int i=instart;i<=inend;i++){

          if(inorder[i]==element){
            return i;
          }

       }
       return -1;
    }*/
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &mp,int &preindex,int instart,int inend,int n){

           //basecase

           if(preindex >= n || instart > inend){
             return NULL;
           }

           int element = preorder[preindex++];
           TreeNode* temp=new TreeNode(element);
           //find the position of preoder element in inorder vector
          // int position=find_pos(inorder,instart,inend,element);
           int position=mp[element];

           //recursioncalls
           temp->left=solve(preorder,inorder,mp,preindex,instart,position-1,n);
           temp->right=solve(preorder,inorder,mp,preindex,position+1,inend,n);

           return temp;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
           
        int preorderindex=0;
        int n = inorder.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=solve(preorder,inorder,mp,preorderindex,0,n-1,n);
        return root;         
    }
};