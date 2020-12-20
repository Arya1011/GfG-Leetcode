//https://practice.geeksforgeeks.org/problems/check-whether-bst-contains-dead-end/1#

bool helper(Node*root,int min_v,int max_v){
    
       //if null node is reached then it means no dead end found
       if(!root){
           return false;
       }
       
       if(root->left==NULL && root->right==NULL)
       
       //dead end found since BST rule violated
       {
             if(root->data-1==min_v && root->data+1==max_v){
              return true;
       }
       
       else {
           return false;
       }
     }
     
       //dead end can be in left or right subtree  
       return (helper(root->left,min_v,root->data) | helper(root->right,root->data,max_v));
     
}

bool isDeadEnd(Node *root)
{
        //Your code here
        
        
        int min_v=0;
        int max_v=INT_MAX;
        return helper(root,min_v,max_v);
}
