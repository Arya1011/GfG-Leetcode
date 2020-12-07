
//https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
TC=O(n1+n2)
SC=O(1)

#include<bits/stdc++.h>
using namespace std;

class Node{


     public:
     int data;
     Node* left;
     Node*right;

     Node(int d){
         this->data=d;
         left=NULL;
         right=NULL;
     }
};

Node* create(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    Node*root=new Node(d);
    root->left=create();
    root->right=create();
    return root;
}


  void inorder(Node*root,vector<int>&ino){

        if(root==NULL){
            return;
        }

        inorder(root->left,ino);
        ino.push_back(root->data);
        inorder(root->right,ino);
        return;
  }


    void inorderHelper(Node*root){

        if(root==NULL){
            return;
        }

        inorderHelper(root->left);
        cout<<root->data<<" ";
        inorderHelper(root->right);
        return;
  }


  vector<int> merge(vector<int> v1,vector<int> v2){

     int i=0;
     int j=0;
     int m=v1.size();
     int n=v2.size();
     vector<int> ans;
     while(i<m && j<n){
         if(v1[i]>v2[j]){
             ans.push_back(v2[j]);
             j++;
         }
         else if(v2[j]>v1[i]){
             ans.push_back(v1[i]);
             i++;
         }
     }

     while(i<m){
         ans.push_back(v1[i]);
         i++;
     }

     while(j<n){
         ans.push_back(v2[j]);
         j++;
     }

     return ans;


  }


Node*helper(vector<int>&ans,int s,int e){
  
      if(s>e){
          return NULL;
      }
      int mid=(s+e)/2;

      Node*root=new Node(ans[mid]);

      root->left=helper(ans,s,mid-1);
      root->right=helper(ans,mid+1,e);
      return root;
}


  Node*formBST(vector<int>&ans){

                int n=ans.size();
                return helper(ans,0,n-1);
  }

 Node* mergeBST(Node*root1,Node*root2)
 {
            vector<int> ino1;
            vector<int> ino2;
            inorder(root1,ino1);
            inorder(root2,ino2);
            vector<int>ans=merge(ino1,ino2);
            Node*root=formBST(ans);
             return root;
 }




 int preIndex=0;
  //O(n)
  Node* treeFromPreorder(int min,int max,vector<int>&pre){
      if(preIndex>=pre.size()){
          return NULL;
      }
       Node*root=new Node(pre[preIndex]);
       if(root->data<=min || root->data>=max){
           return NULL;
       }
       preIndex++;
       root->left=treeFromPreorder(min,root->data,pre);
       root->right=treeFromPreorder(root->data,max,pre);
       return root;
  }



  void mergeBSTOptimized(Node*root1,Node*root2){

        if(!root1 && !root2){
            return;
        }

        if(!root1){
            inorderHelper(root2);
            return;
        }

         if(!root1){
             inorderHelper(root1);
             return;
         }

        //Traverse till the last nodes
        Node*temp1=root1;
        Node*prev1=NULL;

        while(temp1->left){
            prev1=temp1;
            temp1=temp1->left;
        }                     
       
       Node*temp2=root2;
       Node*prev2=NULL;

        while(temp2->left){
             prev2=temp2;
             temp2=temp2->left;
        }      

        if(temp1->data<temp2->data){

               cout<<temp1->data<<" ";

                //root itself
               if(prev1==NULL){
                   mergeBSTOptimized(root1->right,root2);
               }

               else{
                    prev1->left=temp1->right;
                    mergeBSTOptimized(root1,root2);
               }
        }
        else{
              cout<<temp2->data<<" ";

                //root itself
               if(prev2==NULL){
                   mergeBSTOptimized(root1,root2->right);
               }

               else{
                    prev2->left=temp2->right;
                    mergeBSTOptimized(root1,root2);
               }
        }
  }


int main()
{
     Node*root1=create();
     Node*root2=create();

    vector<int>preorder={8,5,1,7,10,12};
   
    //  Node*root4=treeFromPreorder(INT_MIN,INT_MAX,preorder);
      

    //  Node*root3=mergeBST(root1,root2);

     mergeBSTOptimized(root1,root2);
      //inorderHelper(root3);
}
