
class Solution{
  public:
  
  
   Node*merge(Node* first,Node*second){
       
       if(!first){
           return second;
       }
       
       if(!second){
           return first;
       }
       
       if(first->data>=second->data){
             second->next=merge(first,second->next);
             return second;
       }
       
       if(second->data>first->data){
           first->next=merge(first->next,second);
           return first;
       }
       
       return NULL;
       
   }
  
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // your code here
        
        if(!head || !head->next){
            return head;
        }
        
        
        Node*slow=head;
        Node*fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        Node*newHead=slow->next;
        slow->next=NULL;
        
        return merge(mergeSort(head),mergeSort(newHead));
        
        
        
    }
};
