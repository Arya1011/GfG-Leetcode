class Solution
{
    public:
    void helper(string s,string &mx,int k,int idx)
    {
        //swaps over
        if(k==0){
            return;
        }
        int n=s.length();
        
        
        //precompute the next greater character
        
        char max_curr=s[idx];
        
        for(int i=idx+1;i<n;i++){
            if(s[i]>max_curr){
                max_curr=s[i];
            }
        }
        
        if(max_curr!=s[idx]){
            --k;
        }
        
        
            for(int j=idx;j<n;j++){
                if(s[j]==max_curr){
                    swap(s[idx],s[j]);
                    if(s.compare(mx)>0){
                          mx=s;
                    }
                      helper(s,mx,k,idx+1);
                      //backtrack
                      swap(s[idx],s[j]);
            }
        }
    }
    
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
        string mx=str;
        helper(str,mx,k,0);
        return mx;
    }
};
