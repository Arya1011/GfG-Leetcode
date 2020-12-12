
//https://leetcode.com/explore/challenge/card/december-leetcoding-challenge/570/week-2-december-8th-december-14th/3563/

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
    int a,b;
    int ans=INT_MIN;
    priority_queue<pair<int,int>>pq;
    
    
    //O(nlogn)
    void dfs(TreeNode*root,int level){
          if(root==NULL){
              return;
          }
          ans=max(ans,level);
          pq.push({level,root->val});
          dfs(root->left,level+1);
          dfs(root->right,level+1);
          return;
    }
    
    
    //O(n)
    TreeNode*LCA(TreeNode*root,int a,int b){

          if(root==NULL){
              return NULL;
          }
        
          if(root->val==a || root->val==b){
              return root;
          }
        
          TreeNode*l=LCA(root->left,a,b);
          TreeNode*r=LCA(root->right,a,b);
        
        
          if(l!=NULL && r!=NULL){
              return root;
          }
        
         if(l!=NULL){
             return l;
         }
    
         return r;
    
    }
    
    //TC=max(O(nlogn),O(n)) ,SC=O(logn)
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int level=0;
        dfs(root,level);
        
        auto p=pq.top();
        
        int a=p.second;
        pq.pop();
        int b=-1;
        while(!pq.empty()){
            if(pq.top().first==ans){
                b=pq.top().second;
                pq.pop();
            }
            else{
                break;
            }
        }
        
        if(b==-1)b=a;
        
        return LCA(root,a,b);
        
        
    }
};
