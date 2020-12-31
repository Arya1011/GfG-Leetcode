



//2 stacks in one array space efficient approach

#include<bits/stdc++.h>
using namespace std;


class Stack{

      vector<int> arr;
      int size;
      int top1,top2;

      public:
      Stack(int n){
          size=n;
          arr.resize(n);
          top1=-1;
          top2=n;
      }


      void push1(int x){
           if(top1<top2-1){
               top1++;
               arr[top1]=x;
               cout<<"Inserted in stack 1"<<endl;
           }

           else{
               cout<<"Stack 1 is full"<<endl;
               exit(1);
           }
      }

      void pop1(){
  
          if(top1>=0){
              int x=arr[top1];
              top1--;
              cout<<x<<endl;
          }

          else{
              cout<<"Stack Underflow"<<endl;
              exit(1);
          }
      }

      void push2(int x){
          if(top1<top2-1){
              top2--;
              arr[top2]=x;
              cout<<"Inserted in stack 2"
          }
      }

      void pop2(){

            if(top2<n){
                int x=arr[top2];
                top2--;
                cout<<x<<endl;
            }

            else{
                cout<<"Stack underflow"<<endl;
                exit(1);
            }


      }
};


int main(){

    //Write operations here


}
