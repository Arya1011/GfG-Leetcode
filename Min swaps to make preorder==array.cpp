//https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/
class Solution {
public:
    void dfs(TreeNode*root,vector<int>&voyage,int &idx,vector<int>&flipped)
    {
        if(root!=NULL)
        {
             //if root itself is different
        if(root->val!=voyage[idx])
        {
            flipped.clear();
            flipped.push_back(-1);
            return;
        }
        idx++;
        if(root->left!=NULL && idx<voyage.size() && root->left->val!=voyage[idx])
        {
            flipped.push_back(root->val);
            dfs(root->right,voyage,idx,flipped);
            dfs(root->left,voyage,idx,flipped);
        }
        
        else
        {
            dfs(root->left,voyage,idx,flipped);
            dfs(root->right,voyage,idx,flipped);
        }
        return;
        }
    }
    
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) 
    {
        vector<int> flipped;
        int idx=0;
        dfs(root,voyage,idx,flipped);
        if(!flipped.empty() && flipped[0]==-1){
            flipped.clear();
            flipped.push_back(-1);
        }
        return flipped;    
    }
};
