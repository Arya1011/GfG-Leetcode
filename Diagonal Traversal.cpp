class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
         vector<int> ans;
        if(matrix.empty()){
            return {};
        }
         int rows=matrix.size();
         int cols=matrix[0].size();
        
         ans.resize(rows*cols);
        
         int k=0;
         int t2d=0;
         int i=0;
         int j=0;
         while(k<rows*cols){
              if(t2d){
                 ans[k++]=matrix[i++][j--];
                 
                 if(i>=rows){
                     i--;
                     j+=2;
                     t2d=0;
                 }
                  
                 if(j<0){
                     j++;
                     t2d=0;
                 }
                  
                  
              }
             
              else{
                   ans[k++]=matrix[i--][j++];
                 
                  if(j>=cols){
                      i+=2;
                      j--;
                      t2d=1;
                  }
                  
                  if(i<0){
                      i++;
                      t2d=1;
                  }
              }
         }
        return ans;
    }
};
