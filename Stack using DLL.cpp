



//Stack operations in O(1) time using DLL 

#include<bits/stdc++.h>
using namespace std;


class Node{
  public:
  int data;
  Node*next;
  Node*prev;
};


class Stack{
  public:
  Node*head;
  Node*mid;
  //number of nodes
  int count;
};


void push(Stack*s,int d){

      Node*newNode=new Node();

      newNode->data=d;

      newNode->prev=NULL;

      newNode->next=s->head;

     s->count+=1;

     if(s->count==1){
         s->mid=newNode;
     }

     else{
         s->head->prev=newNode;
         if(!((s->count)&1)){
             s->mid=s->mid->prev;
         }
     }

     s->head=newNode;
}

int middle(Stack*s){

     if(s->count==0){
         return -1;
     }

     return s->mid->data;
}


int pop(Stack*s){

      if(s->count==0){
          return -1;
      }

      Node*temp=s->head;
      int popped=temp->data;
      s->head=temp->next;
      if(s->head!=NULL){
            s->head->prev=NULL;
      }
      s->count-=1;
      //middle pointer adjustment
      if(s->count&1){
          s->mid=s->mid->next;
      }
     free(temp);
     return popped;
}


int main()
{

      Stack*s=new Stack();

      push(s,10);
      push(s,9);
      push(s,8);
      push(s,7);
      push(s,6);
      push(s,5);
      push(s,4);

      cout<<pop(s)<<endl;
      cout<<pop(s)<<endl;

      cout<<middle(s);


}
