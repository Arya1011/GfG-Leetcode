class Solution {
public:
    
    int ans=0;
    unordered_set<TreeNode*> s;
    
    
    
    void helper(TreeNode*root,TreeNode*par)
    {
        if(root!=NULL)
        {
             helper(root->left,root);
             helper(root->right,root);
            
            if(par==NULL && s.find(root)==s.end() || s.find(root->left)==s.end() || s.find(root->right)==s.end()){
                    ans++;
                    s.insert(root);
                    s.insert(root->left);
                    s.insert(root->right);
                    s.insert(par);
            }
        }
    }
    
    
    
    
    int minCameraCover(TreeNode* root) {
        s.insert(NULL);
        helper(root,NULL);
        return ans; 
    }
};
