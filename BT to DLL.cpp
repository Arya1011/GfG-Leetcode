//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/1#

void helper(Node*root,Node*&prev,Node*&head){
    
      if(root==NULL)
      {
          return;
      }    
      
      helper(root->left,prev,head);
      
      if(prev==NULL){
          head=root;
      }
      
      else{
           root->left=prev;
           prev->right=root;
      }
    prev=root;
    helper(root->right,prev,head);
}


Node * bToDLL(Node *root)
{
    // your code here
 
    
    
     Node*prev=NULL;
     Node*head=NULL;
    helper(root,prev,head);
    return head;
}
