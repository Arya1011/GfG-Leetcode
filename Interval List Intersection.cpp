class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) 
    {
         vector<vector<int>> ans;
         int sz1=first.size();
         int sz2=second.size();
        
         int i=0;
         int j=0;
        
         
          while(i<sz1 && j<sz2){
              
                vector<int> merged(2);
                 merged[0]=max(first[i][0],second[j][0]);
                 merged[1]=min(first[i][1],second[j][1]);
                
                 if(merged[0]<=merged[1]){
                     ans.push_back(merged);
                 }
              
                
             if(first[i][1]>second[j][1]){
                 j++;
             }
             else{
                 i++;
             }  
                
              
              
          }
         
        
        return ans;
        
    }
};
