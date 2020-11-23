https://leetcode.com/explore/challenge/card/november-leetcoding-challenge/567/week-4-november-22nd-november-28th/3541/

class Solution {
public:
    //Memoize the value obtained for each node being considered as the root node in a map
    map<int,int>mp;
    int helper(TreeNode*root){
        if(root==NULL){
            return 0;        
        }
        if(mp.find(root->val)!=mp.end()){
            return mp[root->val];
        }
        int left=0,right=0;
        //Parent is chosen
        if(root->left!=NULL){
            left=helper(root->left->left)+helper(root->left->right);
        }
        if(root->right!=NULL){
            right=helper(root->right->right)+helper(root->right->left);
        }
        return mp[root->val]=max(left+right+root->val,helper(root->left)+helper(root->right));    
    }
    
    
    int rob(TreeNode* root) {
        if(!root)return 0;
        int ans=helper(root);
        return ans;
        
    }
};
