//https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/569/week-1-december-1st-december-7th/3551/
class Solution {
public:
    int ans=INT_MIN;
    
    void helper(TreeNode*root,int curr){
        if(root==NULL){
            return;
        }
        
        if(!root->left && !root->right){
            ans=max(ans,curr);
            return;
        }
        
        curr+=1;
        helper(root->left,curr);
        helper(root->right,curr);
        
    }
    
    
    
    int maxDepth(TreeNode* root) {
        
        if(!root)return 0;
        helper(root,1);
        return ans;
        
        
    }
};
