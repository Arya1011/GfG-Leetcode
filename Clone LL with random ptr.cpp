

//https://practice.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1#

struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
*/

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    // Your code here
    
     struct Node*curr=head;
     
     //Break next pinter conncection
     while(curr!=NULL){
         Node*nxt=curr->next;
         curr->next=new Node(curr->data);
         curr->next->next=nxt;
         curr=nxt;
     }
     
     
     //Arbitrary pointers
     curr=head;

     while(curr){
         if(curr->arb){
             curr->next->arb=curr->arb->next;
         }
         else{
             curr->next->arb=NULL;
         }
         curr=curr->next->next;
     }
     
     
     //next pointers
     Node*newHead=new Node(0);
     Node*newCurr=newHead;
     curr=head;
     
     while(curr){
         newCurr->next=curr->next;
         curr->next=newCurr->next->next;
         curr=curr->next;
         newCurr=newCurr->next;
     }
     
    
    return newHead->next;
    
}
