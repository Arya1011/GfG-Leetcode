//https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1#

Node* segregate(Node *head) {
    
    // Add code here
    
    Node*oneH=new Node(0);
    Node*zeroH=new Node(0);
    Node*twoH=new Node(0);
    
    Node*temp=head;
    
    
    Node*one=oneH;
    Node*zero=zeroH;
    Node*two=twoH;
    
    while(temp){
        
        if(temp->data==0){
            zero->next=temp;
            zero=zero->next;
            temp=temp->next;
        }
        else if(temp->data==1){
             one->next=temp;
             one=one->next;
             temp=temp->next;
        }
        
        else
        {
             two->next=temp;
             two=two->next;
             temp=temp->next;
            
        }
    }
     zero->next=oneH->next?oneH->next:twoH->next;
     one->next=twoH->next;
     //update head;
     head=zeroH->next;
     return head;
}
