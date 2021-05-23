void helper(int parent[],int i,Node**root,Node*created[]){
    if(created[i]!=NULL){
        return;
    }
    
    created[i]=new Node(i);
    
    //curr node is the root of the tree
    if(parent[i]==-1){
        
        *root=created[i];
        return;
    }
    
    
    //first create all the parent of the given node
    if(created[parent[i]]==NULL){
        helper(parent,parent[i],root,created);
    }
    
    //find parent pointer
    Node*p=created[parent[i]];
    
    if(p->left==NULL){
        p->left=created[i];
    }
    
    else{
        p->right=created[i];
    }
    
    return;
    
    
}


Node *createTree(int parent[], int N)
{
    // Your code here
    
    //keeps track of created nodes
    Node*created[N];
    
    for(int i=0;i<N;i++){
        created[i]=NULL;
    }
    
    
    Node*root=NULL;
    
    for(int i=0;i<N;i++){
        helper(parent,i,&root,created);
    }

    return root;
}
