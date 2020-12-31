



//K Stacks in one array Space Optimized
#include<bits/stdc++.h>
using namespace std;


class KStack{

      vector<int> next;
      vector<int> arr;
      vector<int> top;

      int n,k;
      int free;  //this tells us the next free slot available

      public:
        KStack(int k,int n){
          this->n=n;
          this->k=k;

          //Initialize top vector
          for(int i=0;i<k;i++){
              top[i]=-1;
          }

          //Initialize next vector
          free=0;
          for(int i=0;i<n-1;i++){
              next[i]=i+1;
          }

          next[n-1]=-1;

      }


      bool isFull(){
          return free==-1;
      }

      bool isEmpty(){
          return top[sn]==-1;
      }

      void push(int x,int sn)
      {
           if(isFull()){
               cout<<"Stack is Full"<<endl;
           }
           int i=free;
           free=next[i];
           next[i]=top[sn];
           top[sn]=i;
           arr[i]=x;
      }

      int pop(int sn)
      {
           if(isEmpty()){
               return -1;
           }
           int i=top[sn];
           top[sn]=next[i];
           next[i]=free;
           free=i;
           return arr[i];
      }
};


int main(){

    //Write operations here


}
