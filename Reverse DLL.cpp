

Node* reverseDLL(Node * head)
{
    //Your code here
    
     if(!head || !head->next){
         return head;
     }
     
     while(head->next){
         head=head->next;
     }
     
     Node*temp=head;
     
     while(temp){
         Node*store=temp->next;
         temp->next=temp->prev;
         temp->prev=store;
         temp=temp->next;
     }
    
    return head;
}
