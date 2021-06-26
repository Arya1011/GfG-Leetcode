class BSTIterator {
public:
    stack<TreeNode*>s;
    BSTIterator(TreeNode* root) {
         init(root);
    }
    
    int next() {
        
        TreeNode*curr=s.top();
        s.pop();
        if(curr->right){
            init(curr->right);
        }
        return curr->val;
    }
    
    bool hasNext() {
        
         return !s.empty();
        
        
    }
    
    //SC=O(logn) instead of O(n) and pop operation is O(1)
    private:
    void init(TreeNode*root){
        if(root==NULL)return;
        s.push(root);
        init(root->left);
    }
    
};
