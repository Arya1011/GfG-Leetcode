
//https://leetcode.com/problems/path-sum-iii/

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
    
    
    int ans=0;
    
    
    void helper(TreeNode*root,vector<int>&path,int sum){
        
        
        if(root==NULL){
            return;
        }
        
        path.push_back(root->val);
        helper(root->left,path,sum);
        helper(root->right,path,sum);
        
        int curr_sum=0;
        
        for(int i=path.size()-1;i>=0;i--){
            
             curr_sum+=path[i];
              if(curr_sum==sum){
                  ans++;
              }
        }
        path.pop_back();
    }
    
    
    int pathSum(TreeNode* root, int sum) {
        
         vector<int> path;
         helper(root,path,sum);
         return ans;
        
        
    }
};
