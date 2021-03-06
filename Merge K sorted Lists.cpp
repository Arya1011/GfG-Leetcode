//https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1#

 typedef pair<int,pair<int,int>> customPair;
  
  
Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
        vector<vector<int>>v;
        priority_queue<customPair,vector<customPair>,greater<customPair>>pq;
        for(int i=0;i<N;i++){
             Node*head=arr[i];
             vector<int> temp;
             while(head){
                 temp.push_back(head->data);
                 head=head->next;
             }
             v.push_back(temp);
        }
        //O(log k)
        for(int i=0;i<v.size();i++){
            pq.push({v[i][0],{i,0}});
        }
        vector<int> result;
        
        
        //o(nklogk)  nk traversal logk is for inserting and removing from pq
        while(!pq.empty()){
            customPair curr=pq.top();
            pq.pop();
            int x=curr.second.first;
            int y=curr.second.second;
            
            result.push_back(curr.first);
            
            //check if we have more elements in the same array
            if(y+1<v[x].size()){
                 pq.push({v[x][y+1],{x,y+1}});
            }
        }
        
      Node*newHead=new Node(0);
        
        Node*temp=newHead;
        
        for(auto it:result){
            temp->next=new Node(it);
            temp=temp->next;
        }
        return newHead->next;
       
}


class compare{
   
      public:
         bool operator()(Node*a,Node*b){
              return a->data>b->data;
         }
 };
  
Node * mergeKLists(Node *arr[], int K)
{
       // Your code here
       
       priority_queue<Node*,vector<Node*>,compare> pq;
       for(int i=0;i<K;i++){
           pq.push(arr[i]);
       }
       struct Node*first=NULL;
       struct Node*last=NULL;
       while(!pq.empty()){
           struct Node*top=pq.top();
           pq.pop();
           if(top->next!=NULL){
               pq.push(top->next);
           }
           
           if(first==NULL){
               first=top;
               last=top;
           }
           
           else{
               last->next=top;
               last=top;
           }
       }
       return first;
}

