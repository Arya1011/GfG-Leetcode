





#include<bits/stdc++.h>
using namespace std;



class Node
{
     public:
       Node*left;
       Node*right;
       int data;
       Node(int d){
           this->data=d;
           left=NULL;
           right=NULL;
       }
};

Node*build(){

    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }

    Node*root=new Node(d);
    root->left=build();
    root->right=build();
    return root;
}



// void inorder(Node*root,vector<int>&ino)
// {
//       if(root==NULL){
//           return;
//       }
//       inorder(root->left,ino);
//       ino.push_back(root->data);
//       inorder(root->right,ino);
// }


// vector<int> buildTreeFromLevelOrder(vector<int> arr){
      
  

// }


int min_swaps(vector<int>ino){
    vector<int> temp=ino;

    //O(nlogn)
    sort(temp.begin(),temp.end());

    //count min no of swaps to make original array sorted

    int n=ino.size();

    map<int,int> mp;

    for(int i=0;i<n;i++){
        mp[ino[i]]=i;
    }

    int swaps=0;
    
    //O(n)
    for(int i=0;i<n;i++){
          int tmp=ino[i];
          if(ino[i]!=temp[i]){
              int idx=mp[temp[i]];
              swap(ino[i],ino[idx]);
              swaps++;
              mp[tmp]=mp[temp[i]];
              mp[temp[i]]=i;
          }
    }
    
   return swaps;
}



void helper(vector<int>arr,vector<int>&inorder,int idx)
{
       if(idx>=arr.size()){
           return;
       }
       helper(arr,inorder,2*idx+1);
       inorder.push_back(arr[idx]);
       helper(arr,inorder,2*idx+2);
       return;
}


int main()
{
    //  Node*root=build();
    //  vector<int> ino;
    //  inorder(root,ino);
     vector<int> arr={5,6,7,8,9,10,11};
     vector<int> inorder;
     int idx=0;
     helper(arr,inorder,idx);
     cout<<min_swaps(inorder)<<endl;
}
