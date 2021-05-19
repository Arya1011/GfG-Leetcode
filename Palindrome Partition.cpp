class Solution{
public:
    int palindromicPartition(string str)
    {
        // code here
        
        
        int n=str.size();    
        int P[n][n];
        int C[n];
        memset(P,0,sizeof(P));
        
        
        for(int i=0;i<n;i++){
            P[i][i]=1;
        }
        
        
        
       for(int len=2;len<=n;len++){
           for(int i=0;i<n-len+1;i++){
               int j=i+len-1;
               
               if(len==2)
               {
                   P[i][j]=str[i]==str[j]?1:0;
               }
               
               else
               {
                   P[i][j]=str[i]==str[j] && P[i+1][j-1];
               }
              
           }
       }
       
       
       for(int i=0;i<n;i++){
           if(P[0][i]){
               C[i]=0;
           }
           
           else{
               C[i]=INT_MAX;
               for(int j=0;j<i;j++){
                    if(P[j+1][i] && 1+C[j]<C[i]){
                        C[i]=C[j]+1;
                    }
               }
           }
       }
        
        
        //entire string requires these many cuts
        return C[n-1];
        
    }
};
