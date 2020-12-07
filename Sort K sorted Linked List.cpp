
//https://www.geeksforgeeks.org/sort-k-sorted-doubly-linked-list/

TC:O(nlogk)
SC:O(k)




#include<bits/stdc++.h>
using namespace std;

class node{
     public:
        node*prev;
        node*next;
        int data;    
};




//Setting up custom comparator for priority queue
class compare{
    public:
     bool operator()(node*p1,node*p2){
          return p1->data>p2->data;
     }
};

node* sortK(node*head,int k){

       priority_queue<node*,vector<node*>,compare> pq;
  
       node*newHead=NULL;
       node*last=NULL;

       //first k nodes in the queue
       //O(k)
       for(int i=0;i<=k,head!=NULL;i++){
           pq.push(head);
           head=head->next; 
       }

       //O((n-k)*log(k))
       while(!pq.empty()){
             node*curr=pq.top();
             pq.pop();

            //Its the first node
             if(!newHead){
                 newHead=curr;
                 newHead->prev=NULL;
                 last=newHead;
             }

             else{
                    last->next=curr;
                    curr->prev=last;
                    last=curr;
             }

             //Insert remaining elements
             if(head!=NULL){
                 pq.push(head);
                 head=head->next;
             }
       }
       last->next=NULL;
       return newHead;
}

void insert(node*&head,int key)
{
    node*temp=new node();
    temp->data=key;
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL){
        head->prev=temp;
    }
    head=temp;
}


int32_t main()
{
    node*head=NULL;
     insert(head, 8); 
    insert(head, 56); 
    insert(head, 12); 
    insert(head, 2); 
    insert(head, 6); 
    insert(head, 3); 

    //  while(head){
    //      cout<<head->data<<" ";
    //      head=head->next;
    //  }
     
    node*newHead=sortK(head,2); 
   
     while(newHead){
         cout<<newHead->data<<" ";
         newHead=newHead->next;
     }
    
}
