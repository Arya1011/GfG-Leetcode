//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==NULL){
            return "null";
        }
        
        string s=to_string(root->val);
        string left_s=serialize(root->left);
        string right_s=serialize(root->right);
        
        return s+","+left_s+","+right_s;
    }
    
    
    TreeNode*helper(queue<string>&q){
        
        if(q.empty()){
            return NULL;
        }
        
        string f=q.front();
        q.pop();
        if(f=="null"){
            return NULL;
        }
        
        int n=stoi(f);
        TreeNode*root=new TreeNode(n);
        root->left=helper(q);
        root->right=helper(q);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
          queue<string> q;
           string temp;
          for(int i=0;i<data.size();i++){
              if(data[i]==','){
                   q.push(temp);
                   temp="";
                  continue;
              }
              
              temp.push_back(data[i]);
          }
        
         return helper(q);
        
         
        
        
        
    }
};
