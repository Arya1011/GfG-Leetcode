/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node*iter=head;
        Node*front=head;
        
        //Make copies of each node
        
        while(iter!=NULL)
        {
            front=iter->next;
            Node*copy=new Node(iter->val);
            iter->next=copy;
            copy->next=front;
            iter=front;
        }
        
        
        iter=head;
        //Assign random pointers

         while(iter!=NULL)
         {
             if(iter->random!=NULL){
                iter->next->random=iter->random->next;
             }
             iter=iter->next->next;
         }
        
        
        
        //Seperate the two lists
        
        iter=head;
        Node*pseudohead=new Node(0);
        Node*copy=pseudohead;
        
        while(iter!=NULL){
            
            front=iter->next->next;
            copy->next=iter->next;
            
            //restore original list
            iter->next=front;
            copy=copy->next;
            iter=front;
        }
        
        return pseudohead->next;
        
        
    }
};
