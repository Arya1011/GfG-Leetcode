//https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

// Return True if the given trees are isomotphic. Else return False.
bool isIsomorphic(Node *root1,Node *root2)
{
       //add code here.
       
     if(!root1 && !root2){
         return true;
     }
    
      if(!root1 || !root2){
          return false;
      }
      
      if(root1->data!=root2->data){
          return false;
      }
     
     bool op1=root1->data==root2->data;
     
     bool op2=isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);
     
     bool op3=isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);
     
     return op1 && (op2 || op3);
       

}
