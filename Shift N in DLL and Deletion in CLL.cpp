





#include<bits/stdc++.h>
using namespace std;



// class Node{
//  public:
//     Node*next=NULL;
//     int data;

//     Node(int d){
//         this->data=d;
//         this->next=NULL;
//     }
// };



class Node{
  public:
   Node*next;
   Node*prev;
   int data;
   Node(int d){
       this->next=NULL;
       this->prev=NULL;
       this->data=d;
   }
};


//circular linked list deletion
Node* deleteNode(Node*&head,int data){
    if(head->data==data && head->next==NULL){

             free(head);
             head=NULL;
             return head;
    }
      Node*last=head;
       Node*d;

     if(head->data==data){
          
          while(last->next!=head){
              last=last->next;
          }

          last->next=head->next;
          free(head);
          head=last->next;
     }

    while(last->next!=head && last->next->data!=data){
         last=last->next;
    }

    if(last->next->data==data)
    {
         d=last->next;
         last->next=d->next;
         free(d);
         head=last->next;
    }
   return head;
}


void push(Node*&newHead,Node*C){

       C->prev=NULL;
       C->next=newHead;

       if(newHead!=NULL)
       {
           newHead->prev=C;
       }
       newHead=C;
}


Node* shiftN(Node*&head,int N){

      int len=0;

      Node*temp=head;
      while(temp){
          len++;
          temp=temp->next;
      }

      if(N%len==0){
          return head;
      }
       temp=head;
      int ctr=1;
      while(ctr<N && temp){
          ctr++;
          temp=temp->next;
      }
      Node*newHead=temp->next;
      temp->next=NULL;
      temp=newHead;
      while(temp->next){
          temp=temp->next;
      }
      temp->next=head;
      newHead->prev=NULL;
      return newHead;
}


Node* KReverse(Node*&head , int k){

       Node*C=head;
       Node*N=NULL;
       Node*P=NULL;


       Node*newHead=NULL;

       int i=0;
       while(C!=NULL && i<k){
           N=C->next;
           push(newHead,C);
           C=N;
           i++;
       }

       if(N!=NULL){
           head->next=KReverse(N,k);
           head->next->prev=head;
       }
return newHead; 
}



int main(){


    Node*head=NULL;

    Node*first1=new Node(8);
    Node*first2=new Node(7);
    Node*first3=new Node(6);
    Node*first4=new Node(5);
    Node*first5=new Node(4);
    Node*first6=new Node(3);
    Node*first7=new Node(2);
    Node*first8=new Node(1);

    push(head,first1);
    push(head,first2);
    push(head,first3);
    push(head,first4);
    push(head,first5);
    push(head,first6);
    push(head,first7);
    push(head,first8);

    // Node*newHead=KReverse(head,2);
    Node*newHead=shiftN(head,4);

    while(newHead){
        cout<<newHead->data<<" ";
        newHead=newHead->next;
    }




}
