
//https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/




#include<bits/stdc++.h>
using namespace std;



class Node{
public:
 int data;
 Node*left;
 Node*right;

  Node(int d){
      this->data=d;
      left=NULL;
      right=NULL;
  }

};


int helper2(string s,int si,int ei){

       if(si>ei){
           return -1;
       }

        stack<int> st;
        for(int j=si;j<=ei;j++){
            if(s[j]=='('){
                st.push(s[j]);
            }

            //left subtree exists
            else if(s[j]==')'){
                if(st.top()=='('){
                    st.pop();
                    if(st.empty()){
                        return j;
                    }
                }
            }
        }
return -1;
}


Node* helper1(string s,int si,int ei){
    if(si>ei){
        return NULL;
    }

     Node*root=new Node(s[si]-'0');
     int idx=-1;
     if(si+1<=ei && s[si+1]=='('){
         //find index of closing bracket
          idx=helper2(s,si+1,ei);
     }

     if(idx!=-1){
         root->left=helper1(s,si+2,idx-1);
         root->right=helper1(s,idx+2,ei-1);
     }
     return root;
}

void preorder(Node*root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}

void solve(){
     string s;
     cin>>s;
      int n=s.size();
     Node*root=helper1(s,0,n-1);

     preorder(root);
}

int main(){

   solve();


}
