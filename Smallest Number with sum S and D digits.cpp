 string smallestNumber(int S, int D){
        // code here 
        
        if(S==0){
            if(D==1){
                return "0";
            }
            
            else{
                return "-1";
            }
        }
        
        if(S>9*D){
            return "-1";
        }
        
        
        string res;
        vector<int> res_i(D);
        //we subtract 1 so that in the end when the (D-1)  reminaing digits are used, we can simply place the least digit possible ie., S' + 1 at the beginning where S' is the remaining sum
        S-=1;
        int i;
        for(i=D-1;i>0;i--)
        {
            if(S>9)
            {
                res_i[i]=9;
                S-=9;
            }
            
            else
            {
                res_i[i]=S;
                S=0;
            }
        }
        
        
        res_i[i]=S+1;
        
        for(int i=0;i<D;i++)
        {
        
           res+=(to_string(res_i[i]));
            
        }
        
        return res;
        
        
    }
