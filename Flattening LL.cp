
 //https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1#
 
    Node*merge(Node*head1,Node*head2){
        if(!head1){
            return head2;
        }
        
        if(!head2){
            return head1;
        }
        
        Node*final;
        
        if(head1->data<head2->data){
            final=head1;
            final->bottom=merge(head1->bottom,head2);
        }
        
        else{
            final=head2;
            final->bottom=merge(head1,head2->bottom);
        }
        return final;
        
    }
    
    
Node *flatten(Node *root)
{
   // Your code here
   
   Node*head1=root;
   Node*head2=root->next;
   
   while(head2!=NULL){
       //store the next node
       Node*head3=head2->next;
       head1=merge(head1,head2);
       head2=head3;
   }
   
   return head1;
   
}
