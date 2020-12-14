
//https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1

vector <int> zigZagTraversal(Node* root)
{
	// Code here
	deque<Node*> dq;
	bool l2r=true;
	dq.push_back(root);
	vector<int> ans;
	while(!dq.empty()){
	     int size=dq.size();
	     while(size--){
	         if(l2r){
	             Node*curr=dq.back();
	             dq.pop_back();
	             ans.push_back(curr->data);
	             if(curr->left){
	                 dq.push_front(curr->left);
	             }
	             if(curr->right){
	                 dq.push_front(curr->right);
	             }
	         }
	         else{
	             Node*curr=dq.front();
	             dq.pop_front();
	             ans.push_back(curr->data);
	             if(curr->right){
	                 dq.push_back(curr->right);
	             }
	             if(curr->left){
	                 dq.push_back(curr->left);
	             }
	         }
	     }
	    //row is complete
	    l2r=!l2r;
	}
	return ans;
}
