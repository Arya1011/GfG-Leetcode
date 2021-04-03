//https://practice.geeksforgeeks.org/problems/minimum-swaps-for-bracket-balancing2704/1

    int open=0;
        int closed=0;
        
        int swaps=0;
        int wrong=0;
        
        int i=0;
        
        int n=S.size();
        
        while(i<n){
            
            if(S[i]=='['){
                
                open++;
                
                if(wrong>0){
                    swaps+=wrong;
                    wrong--;
                }
                
                
            }
            
            else{
                
                closed++;
                wrong=closed-open;
            }
            
            
        }
        
        return swaps;
