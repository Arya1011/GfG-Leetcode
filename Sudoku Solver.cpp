

class Solution {
  public:
  
  
    void printGrid (int grid[][N]) 
    {
        // Your code here 
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                cout<<grid[i][j]<<" ";
            }
        }
    }
  
   bool check(int grid[][N],int i,int j,int number){
       
           //row and column must not have the number
           
           for(int k=0;k<N;k++)
           {
               if(grid[i][k]==number || grid[k][j]==number){
                   return false;
               }
           }
           
           
           
           //subgrid must not have have number
       
           int sqn=sqrt(N);
           int sx=(i/sqn)*sqn;
           int sy=(j/sqn)*sqn;
           
           for(int row=sx;row<sx+sqn;row++){    
               for(int col=sy;col<sy+sqn;col++){
                   if(grid[row][col]==number){
                       return false;
                   }
               }
           }
       
        return true;
       
       
   }
  
  
    bool helper(int grid[][N],int i,int j)
    {
        
        if(i==N)
        {
           //printGrid(grid);
           return true;
           
        }
        
        
        if(j==N)
        {
            return helper(grid,i+1,0);
        }
        
        if(grid[i][j]!=0)
        {
            return helper(grid,i,j+1);
        }
        
        //we try all options at the current spot
        
        for(int number=1;number<=N;number++)
        {
           
            if(check(grid,i,j,number)){
                 grid[i][j]=number;
                 bool can_we_place=helper(grid,i,j+1);
                 if(can_we_place)
                 {
                     return true;
                 }
                      grid[i][j]=0;
            }
        }
         return false;
    }
  
  
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
        return helper(grid,0,0);
        
        
    }
    
   
};

/
