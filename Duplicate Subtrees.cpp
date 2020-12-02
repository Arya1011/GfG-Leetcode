//https://leetcode.com/problems/find-duplicate-subtrees/
class Solution {
public:
    map<string,int>mp;
    vector<TreeNode*> ans;
        
    string helper(TreeNode*root){
        if(root==NULL){
            return "$";
        }
        
        //Encode the subtree as a string
        string s=to_string(root->val)+","+helper(root->left)+","+helper(root->right);
        if(mp[s]==1){
            ans.push_back(root);
        }
        
        //Include the string in the map
        mp[s]++;
        
        return s;
        
        
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
           helper(root);
        
           return ans;
        
    }
};
