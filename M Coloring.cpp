bool isSafe(bool graph[101][101],int curr,int V,int c,vector<int>&colors){
    
    
     for(int i=0;i<V;i++){
         
         if(graph[i][curr] && colors[i]==c){
             return false;
         }
         
         
     }
    
    return true;
    
}




bool helper(bool graph[101][101],int curr,int m,int V,vector<int>&colors){
    
     //all vertices colored
     if(curr==V){
         return true;
     }
     
     
     //assign colors
     for(int c=0;c<m;c++)
     {
         if(isSafe(graph,curr,V,c,colors)){
             colors[curr]=c;
             //call on remaining graph
             if(helper(graph,curr+1,m,V,colors)){
                 return true;
             }
             //else backtrack
             colors[curr]=-1;
         }
     }
    return false;
}


bool graphColoring(bool graph[101][101], int m, int V)
{
    // your code here
    
    vector<int> colors(V,-1);
    
    return helper(graph,0,m,V,colors);
    
    
}
